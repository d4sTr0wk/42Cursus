/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:20:44 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:40:42 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	cnt;
	char	*first_occurrence;

	i = 0;
	if (*(little) == '\0')
		return ((char *)big);
	if ((ft_strlen(big) < ft_strlen(little)) || (ft_strlen(little) > len))
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		cnt = 0;
		while (big[i] == little[cnt] && i < len)
		{
			cnt++;
			if (cnt == 1)
				first_occurrence = (char *)(big + i);
			if (cnt == len || *(little + cnt) == '\0')
				return (first_occurrence);
			++i;
		}
		i = i - cnt + 1;
	}
	return (NULL);
}
