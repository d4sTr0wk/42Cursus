/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:32 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/17 11:35:14 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = read_file(&static_buffer, buffer, fd);
	free(buffer);
	return (line);
}

char	*read_file(char **stat_buf, char *buf, int fd)
{
	ssize_t	read_bytes;
	int		point_nl_seek;
	int		nl;
	int		look_for_nl;
	char	*ln;

	nl = 0;
	look_for_nl = 0;
	if (*stat_buf)
		look_for_nl = 1;
	while (!nl)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(*stat_buf), *stat_buf = NULL, NULL);
		buf[read_bytes] = '\0';
		point_nl_seek = strjoin_buf(stat_buf, buf, read_bytes);
		if (point_nl_seek < 0 || (!point_nl_seek && !read_bytes))
			return (end_of_file(stat_buf, ln));
		nl = newline(stat_buf, &ln, point_nl_seek, look_for_nl);
		if (nl == -1)
			return (free(*stat_buf), *stat_buf = NULL, NULL);
	}
	return (ln);
}

int	strjoin_buf(char **stat_buf, char *buf, ssize_t read_bytes)
{
	char	*aux_buffer;
	int		i;
	int		tam_auxbuf;
	int		tam_statbuf;

	if (!read_bytes)
		return (0);
	tam_auxbuf = newbuffer_tam(stat_buf, read_bytes);
	aux_buffer = (char *)malloc(tam_auxbuf * sizeof(char));
	if (!aux_buffer)
		return (-1);
	i = 0;
	while ((*stat_buf) != NULL && (*stat_buf)[i] != '\0')
	{
		aux_buffer[i] = (*stat_buf)[i];
		i++;
	}
	tam_statbuf = i;
	while ((i++) < tam_auxbuf)
		aux_buffer[i - 1] = buf[(i - 1) - tam_statbuf];
	free(*stat_buf);
	*stat_buf = aux_buffer;
	return (tam_statbuf);
}

int	newline(char **stat_buf, char **ln, int point_nl_seek, int look_for_nl)
{
	int	i;
	int	j;

	if (!look_for_nl)
		i = point_nl_seek;
	else
		i = 0;
	while ((*stat_buf)[i])
	{
		if ((*stat_buf)[i] == '\n')
		{
			*ln = (char *)malloc((i + 2) * sizeof(char));
			if (!(*ln))
				return (-1);
			j = -1;
			while ((++j) != (i + 1))
				(*ln)[j] = (*stat_buf)[j];
			(*ln)[j] = '\0';
			return (delete_newline(stat_buf, (i + 1)));
		}
		i++;
	}
	return (0);
}

int	delete_newline(char **stat_buf, int pointer_endnl)
{
	char	*aux_buf;
	int		i;
	int		end_surplus;

	i = pointer_endnl;
	if ((*stat_buf) == NULL || (*stat_buf)[i] == '\0')
		return (free(*stat_buf), *stat_buf = NULL, 1);
	while ((*stat_buf)[i])
		i++;
	end_surplus = i;
	aux_buf = (char *)malloc((end_surplus - pointer_endnl + 1) * sizeof(char));
	if (!aux_buf)
		return (-1);
	i = pointer_endnl - 1;
	while ((*stat_buf)[++i])
		aux_buf[i - pointer_endnl] = (*stat_buf)[i];
	aux_buf[i - pointer_endnl] = '\0';
	free(*stat_buf);
	*stat_buf = aux_buf;
	return (1);
}
