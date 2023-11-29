/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:15:37 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:40:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (*(s1 + (++j)))
		*(new + (++i)) = (char)(*(s1 + j));
	j = -1;
	while (*(s2 + (++j)))
		*(new + (++i)) = (char)(*(s2 + j));
	new[++i] = 0;
	return (new);
}
