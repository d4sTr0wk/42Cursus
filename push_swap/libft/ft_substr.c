/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:21:23 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:36:09 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	int		book;

	if (start >= ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (ft_strlen(s) - start >= len)
		book = (len + 1);
	else
		book = (ft_strlen(s) - start + 1);
	substr = (char *)malloc((book) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = -1;
	while (++i < book - 1)
		substr[i] = (char)(s[start + i]);
	substr[i] = '\0';
	return (substr);
}
