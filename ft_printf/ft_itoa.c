/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/09/20 12:49:55 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 21:13:43 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int	ft_itoa(int n)
{
	char	*itoa;
	int		n_dig;
	int		aux;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	n_dig = count_digits(n);
	aux = n_dig;
	itoa = (char *)malloc(sizeof(char) * (n_dig + 1));
	if (!itoa)
		return (-1);
	itoa[n_dig] = '\0';
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		n_dig++;
	}
	while (aux-- > 0)
	{
		itoa[aux] = (n % 10) + 48;
		n /= 10;
	}
	ft_putstr(itoa);
	return (free(itoa), n_dig);
}
