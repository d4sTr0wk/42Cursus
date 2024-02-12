/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:48:22 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/23 20:14:31 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_str(char const *str, va_list args);
static int	conversion(char c, va_list args);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		characters;

	va_start(args, str);
	characters = write_str(str, args);
	va_end(args);
	return (characters);
}

static int	write_str(char const *str, va_list args)
{
	int	i;
	int	cnt;
	int	aux;

	i = -1;
	cnt = 0;
	va_end(args);
	while (str[++i])
	{
		if (str[i] != '%')
			cnt += write(1, &(str[i]), 1);
		else
		{
			aux = conversion(str[++i], args);
			if (aux == (-1))
				return (-1);
			else
				cnt += aux;
		}
	}
	return (cnt);
}

static int	conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	if ((c == 'd') || (c == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if ((c == 'x') || (c == 'X'))
		return (ft_puthex(c, va_arg(args, int)));
	if (c == '%')
		return (ft_putchar(c));
	return (-1);
}
