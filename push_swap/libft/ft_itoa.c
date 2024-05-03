/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:49:55 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:41:31 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int				cnt;
	unsigned int	aux;

	cnt = 0;
	if (n < 0)
	{
		aux = n * (-1);
		cnt++;
	}
	else
		aux = n;
	while (aux != 0)
	{
		aux /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		n_dig;
	int		limit;
	long	aux;

	if (n == 0)
		return (ft_strdup("0"));
	n_dig = count_digits(n);
	itoa = (char *)malloc(sizeof(char) * (n_dig + 1));
	if (!itoa)
		return (NULL);
	(free(NULL), itoa[n_dig] = '\0', limit = 0, aux = n);
	if (aux < 0)
	{
		itoa[0] = '-';
		aux *= (-1);
		limit++;
	}
	while (n_dig-- > limit)
	{
		itoa[n_dig] = (aux % 10) + 48;
		aux /= 10;
	}
	return (itoa);
}
