/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:00:59 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/25 20:03:56 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

void	ft_strcpy(char **dst, const char *src)
{
	int	i;

	if (src == NULL || ft_strlen(src) == 0)
		*dst = NULL;
	else
	{
		*dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
		if (*dst)
		{
			i = -1;
			while (src[++i] != '\n' && src[i] != '\0')
				(*dst)[i] = src[i];
			if (src[i] == '\n')
				(*dst)[i++] = '\n';
			(*dst)[i] = '\0';
		}
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

char	*end_of_file(char **stat_buf, char *ln)
{
	if (*stat_buf && (*stat_buf)[0])
	{
		ft_strcpy(&ln, *stat_buf);
		delete_newline(stat_buf, ft_strlen(ln));
		return (ln);
	}
	return (free(*stat_buf), *stat_buf = NULL, NULL);
}
