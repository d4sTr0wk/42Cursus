/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:05:16 by maxgarci          #+#    #+#             */
/*   Updated: 2024/02/24 14:06:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%i", a->value);
			a = a->next;
		}
		else
			ft_printf(" ");
		ft_printf(" ");
		if (b)
		{
			ft_printf("%i", b->value);
			b = b->next;
		}
		else
			ft_printf(" ");
		ft_printf("\n");
	}
	ft_printf("- -\na b\n\n");
}

int	ft_atoi(const char *nptr, int *error)
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
		*error = 1;
	}
	return ((int)(num * sign));
}
