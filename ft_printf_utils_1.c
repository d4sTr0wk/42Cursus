/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:02:35 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/23 20:47:09 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

static int	recursive_hex(char *dic, unsigned long long hex, int cnt)
{
	if (hex > 15)
	{
		cnt += recursive_hex(dic, (hex / 16), cnt);
		cnt += ft_putchar(*(dic + (hex % 16)));
	}
	else
		return (ft_putchar(*(dic + hex)));
	return (cnt);
}

int	ft_puthex(char c, unsigned long long hex)
{
	char	*dictionary;

	if ((c == 'x') || (c == 'p'))
		dictionary = "0123456789abcdef";
	else
		dictionary = "0123456789ABCDEF";
	if (c == 'p')
		return (recursive_hex(dictionary, hex, 0));
	else
		return (recursive_hex(dictionary, (unsigned int)hex, 0));
}

int	ft_putnbr(long nbr)
{
	int	len;

	if (nbr == 0)
		return (write(1, "0", 1));
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	len += write(1, &"0123456789"[nbr % 10], 1);
	return (len);
}
