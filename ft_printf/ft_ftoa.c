/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:52:49 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 23:34:28 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_ftoa(double n)
{
	int	c1;
	int	c2;
	int	c3;
	int	i;
	unsigned long	integer_aux;

	c1 = ft_putstr(ft_itoa((int)n));
	c2 = ft_putchar('.');
	n -= (int)n;
	i = -1;
	while (((n - (int)n)  != 0) && (++i < 15))
		n *= 10;
	integer_aux = (long)n;
	while (integer_aux % 10 == 0)
		integer_aux /= 10;
	c3 = ft_putstr(ft_itoa(integer_aux));
	if (c1 < 0 || c2 < 0 || c3 < 0)
		return (-1);
	else
		return (c1 + c2 + c3);
}
