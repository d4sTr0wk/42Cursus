/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:21:08 by maxgarci          #+#    #+#             */
/*   Updated: 2024/04/01 23:58:23 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum)
{
	static unsigned char	character = 0;
	static int				bit_index = 0;

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
	}
	else
		character <<= 1;
}

int	main(void)
{
	int pid;
	
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	pid = getpid();
	ft_putstr_fd(GREEN "Server PID: " RESET, 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		;
	return (0);
}
