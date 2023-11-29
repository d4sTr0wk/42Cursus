/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:13:28 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:38:44 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursive(long n, int fd)
{
	if (n >= 10)
		recursive((n / 10), fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	aux;

	aux = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux *= (-1);
	}
	else
		aux = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		recursive(aux, fd);
}
