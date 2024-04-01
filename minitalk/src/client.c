/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:19:20 by maxgarci          #+#    #+#             */
/*   Updated: 2024/04/01 19:26:15 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    sendSignal(int pid, unsigned char character)
{
    int i;
    int err;

    i = CHAR_BIT;
    
    while (--i > 0)
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

void    sendMessage(int pid, char *message)
{
    int i;

    i = 0;
    while (message[i] != '\0')
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

    if (argc != 3)
    {
        ft_putstr_fd("Error with arguments\n", 2);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    message = argv[2];
    sendMessage(pid, message);
	return (0);
}
