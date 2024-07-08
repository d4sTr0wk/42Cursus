/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:19:20 by maxgarci          #+#    #+#             */
/*   Updated: 2024/07/08 18:21:11 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int signum, siginfo_t *info, void *)
{
	if (signum == SIGUSR2)
	{
		exit(1);	
	}
}

void    send_signal(int pid, unsigned char character)
{
    int i;
    int err;

    i = CHAR_BIT;
    
    while (i-- > 0)
    {
        if ((character >> i ) & 1)
            err = kill(pid, SIGUSR1);
        else
            err = kill(pid, SIGUSR2);
        if (err == -1)
        {
            ft_putstr_fd("Error: sendSignal", 2);
            return ;
        }
        usleep(42);
    }
}

int    send_message(int pid, char *message)
{
    int i;

    i = -1;
    while (message[++i] != '\0')
        sendSignal(pid, message[i]);
    if (kill(pid, '\0'))
    {
        ft_putstr_fd("Error: sendMessage", 2);
        return ;
    }
}

int	main(int argc, char **argv)
{
    char    *message;
	int     pid;
	
	signal(SIGUSR1, sig_handler); 
    if (argc != 3)
    {
        ft_putstr_fd("Error with arguments\n", 2);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    message = argv[2];
    if (sendMessage(pid, message) == 1)
	{
		ft_putstr_fd("client_bonus: sendMessage error", 1);
		return (1);
	}
	return (0);
}
