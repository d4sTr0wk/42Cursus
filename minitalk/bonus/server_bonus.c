/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:21:08 by maxgarci          #+#    #+#             */
/*   Updated: 2024/07/26 15:01:01 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	character = 0;
	static int				bit_index = 0;

	(void)ucontext;
	character |= (signum == SIGUSR1);
	bit_index++;
	if (bit_index == CHAR_BIT)
	{
		if (character == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(character, 1);
		character = 0;
		bit_index = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		character <<= 1;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putstr_fd(RED "server_bonus: sigaction error" RESET, 2);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd(GREEN "Server PID: " RESET, 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
