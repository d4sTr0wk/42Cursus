/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:49:55 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:41:53 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		sign = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = (str[i++] - '0') + num * 10;
	return ((unsigned)num * sign);
}
