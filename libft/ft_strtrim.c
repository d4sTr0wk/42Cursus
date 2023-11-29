/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:34:14 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:36:30 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;

	if (!(*s1))
		return (ft_strdup(""));
	i = -1;
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + (++i)) && ft_strchr(set, *(s1 + i)))
		start++;
	i = end;
	while (*(s1 + (--i)) && ft_strchr(set, *(s1 + i)))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
