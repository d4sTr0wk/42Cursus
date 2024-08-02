/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:19:20 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/02 11:01:23 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	count = 0;

	(void)info;
	(void)ucontext;
	if (signum == SIGUSR2)
		count++;
	else if (signum == SIGUSR1)
	{
		if (count != 7)
		{
			ft_putnbr_fd(count, 2);	
			ft_putstr_fd(RED "Error: Message not received\n" RESET, 2);
		}
		else
			ft_putstr_fd(GREEN "Message received\n" RESET, 1);
		count = 0;
	}
}

static void	send_signal(int pid, unsigned char character)
{
    int i;
    int err;

    i = CHAR_BIT;
	ft_putstr_fd(YELLOW, 1);
	if (character == '\0')
		ft_putstr_fd("\\0", 1);
	else
		ft_putchar_fd(character, 1);
	ft_putstr_fd(": " RESET, 1);
    while (i-- > 0)
    {
        if ((character >> i ) & 1)
            err = kill(pid, SIGUSR1);
        else
            err = kill(pid, SIGUSR2);
        if (err == -1)
        {
            ft_putstr_fd(RED "Error: send_signal" RESET, 2);
            return ;
        }
        usleep(100);
    }
}

static void	send_message(int pid, char *message)
{
    int i;

    i = -1;
    while (message[++i] != '\0')
	{
        send_signal(pid, message[i]);
	}
	send_signal(pid, '\0');
}

int	main(int argc, char **argv)
{
    char    			*message;
	int     			pid;
	struct sigaction	sa;
	
	if (argc != 3)
    {
        ft_putstr_fd(RED "Error with arguments\n" RESET, 2);
        return (1);
    }
	sa.sa_sigaction = sig_handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putstr_fd(RED "client_bonus: sigaction error" RESET, 2);
		return (1);
	}
    pid = ft_atoi(argv[1]);
    message = argv[2];
    send_message(pid, message);
	return (0);
}
