/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:46 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 21:12:22 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		tam;

	if (!s1)
		return (NULL);
	tam = ft_strlen(s1);
	if (tam == 0)
	{
		ptr = malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	ptr = (char *)malloc((tam + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < tam)
		ptr[i] = s1[i];
	ptr[tam] = '\0';
	return (ptr);
}
