/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:46 by maxgarci          #+#    #+#             */
/*   Updated: 2025/04/18 18:15:47 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		tam;

	tam = ft_strlen(s1);
	if (tam == -1)
		write(2, "hola", 4);
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
