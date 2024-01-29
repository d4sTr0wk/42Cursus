/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:35:36 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/28 21:35:36 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, int *err)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		++i;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		++i;
	}
    if (nptr[i] != '\0')
    {
        num = 0;
        *err = 1;
    }
	return ((int)(num * sign));
}