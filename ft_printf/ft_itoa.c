/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:49:55 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 21:13:43 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	count_digits(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while(n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int	n_dig;
	int	limit;

	if (n == 0)
		return(ft_strdup("0"));
	n_dig = count_digits(n);
	itoa = (char *)malloc(sizeof(char) * (n_dig + 1));
	if(!itoa)
		return (NULL);
	itoa[n_dig] = '\0';
	limit = 0;
	if (n < 0)
	{
		itoa[0] = '-';
		n *= -1;
		limit++;
	}
	while (n_dig-- > limit)
	{
		itoa[n_dig] = (n % 10) + 48;
		n /= 10;
	}
	return (itoa);	
}
