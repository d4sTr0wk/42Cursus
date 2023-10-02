/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:49:55 by maxgarci          #+#    #+#             */
/*   Updated: 2023/09/20 13:00:08 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
	int	aux_dig;
	int	digit;

	if (n == 0)
		return(strdup("0"));
	n_dig = count_digits(n);
	itoa = (char *)malloc(sizeof(char) * (n_dig + 1));
	if(!itoa)
		return (NULL);
	itoa[n_dig] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		n *= -1;
	}
	while (n_dig > 0)
	{
		itoa[--n_dig] = n % 10;
		n /= 10;
	}
	return (itoa);	
}
