/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:00:59 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/17 10:55:25 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	if (str == NULL)
		return (0);
	while (*(str + (cnt)) != '\0')
		++cnt;
	return (cnt);
}

void	ft_strcpy(char **dst, const char *src)
{
	int	i;

	if (src == NULL || ft_strlen(src) == 0)
		*dst = NULL;
	else
	{
		*dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
		i = -1;
		while (src[++i] != '\n' && src[i] != '\0')
			(*dst)[i] = src[i];
		if (src[i] == '\n')
			(*dst)[i++] = '\n';
		(*dst)[i] = '\0';
	}
}

int	newbuffer_tam(char **stat_buf, ssize_t read_bytes)
{
	int	i;

	i = 0;
	while ((*stat_buf) != NULL && (*stat_buf)[i] != '\0')
		i++;
	return (i + (int)read_bytes + 1);
}
