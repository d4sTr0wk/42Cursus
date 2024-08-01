/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:19:20 by maxgarci          #+#    #+#             */
/*   Updated: 2024/07/26 18:46:53 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    send_signal(int pid, unsigned char character)
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
            ft_putstr_fd(RED "Error: send_signal" RESET, 2);
            return ;
        }
        usleep(100);
    }
}

static void    send_message(int pid, char *message)
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
    char    *message;
    int     pid;

    if (argc != 3)
    {
        ft_putstr_fd(RED "Error with arguments\n" RESET, 2);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    message = argv[2];
    send_message(pid, message);
	return (0);
}
