/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:41:53 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:40:34 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (!src || *src == '\0')
		return (lendst + lensrc);
	if (dstsize < lendst)
		return (lensrc + dstsize);
	if (dstsize == 0)
		return (lensrc);
	i = lendst;
	j = 0;
	while (i < (dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = '\0';
	return (lendst + lensrc);
}
