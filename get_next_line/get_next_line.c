/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:32 by maxgarci          #+#    #+#             */
/*   Updated: 2023/12/07 14:25:55 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
#endif

char	*read_file(char **stat_buf, char *buf, char *ln, int fd, ssize_t read_bytes);
int	strjoin_buf(char **stat_buf, char *buf, ssize_t read_bytes);
int	newline(char **stat_buf, char **ln, int point_nl_seek);
int	delete_newline(char **stat_buf, int pointer_endnl);

char	*get_next_line(int fd)
{
	static char	*static_buffer = 0;
	char		*buffer;
	char		*line;
	ssize_t		read_bytes;

	line = 0;
	read_bytes = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	return(read_file(&static_buffer, buffer, line, fd, read_bytes));
}

char	*read_file(char **stat_buf, char *buf, char *ln, int fd, ssize_t read_bytes)
{
	int	point_nl_seek;
	int	no_nl;

	no_nl = 0;
	while (!no_nl)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (!read_bytes)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		point_nl_seek = strjoin_buf(stat_buf, buf, read_bytes);
		if (read_bytes < BUFFER_SIZE)
			return (*stat_buf);
		// read_bytes = BUFFER_SIZE
		no_nl = newline(stat_buf, &ln,  point_nl_seek); //Compruebo si hay salto de línea en los nuevos caracteres introducidos para eso uso point_nl_seek para marcar desde donde empiezo a buscar
		if (no_nl < 0) // Fallo en malloc
			return (NULL);
	}
	return (ln);
}

int	strjoin_buf(char **stat_buf, char *buf, ssize_t read_bytes)
{
	int	i;
	char	*aux_buffer;
	int	tam_auxbuf;
	int	tam_statbuf;

	i = 0;
	while ((*stat_buf) && (*stat_buf)[i]) // Leo cuántos bytes tiene el static_buffer
		i++;
	tam_statbuf = i;
	tam_auxbuf = i + (int)read_bytes + 1; 
	aux_buffer = (char *)malloc(tam_auxbuf * sizeof(char)); // Almaceno en memoria cuántos caracteres tenía antes más los nuevos leídos
	if (!aux_buffer)
		return (0);
	i = -1;
	while ((++i) < tam_statbuf)
		aux_buffer[i] = (*stat_buf)[i];
	while (i < tam_auxbuf) // Copia lectura en buffer hasta \0 en aux_buffer
	{
		aux_buffer[i] = buf[i- tam_statbuf];
		++i;
	}
	aux_buffer[i] = '\0';
	free(*stat_buf);
	*stat_buf = aux_buffer;
	return (tam_statbuf);
}

int	newline(char **stat_buf, char **ln, int point_nl_seek)
{
	int	i;
	int	j;

	i = point_nl_seek;
	while ((*stat_buf)[i])
	{
		if ((*stat_buf)[i] == '\n') // Encontrada nueva línea
		{
			*ln = (char *)malloc((i + 1) * sizeof(char));
			if (!ln)
				return (-1);
			j = -1;
			while ((++j) != (i + 1))
				(*ln)[j] = (*stat_buf)[j];
			(*ln)[j] = '\0'; // Nueva línea generada
			return (delete_newline(stat_buf, (i + 1))); //Devuelve que ha habido nueva línea
		}
		i++;
	}
	return (0);
}

int	delete_newline(char **stat_buf, int pointer_endnl)
{
	int	i;
	int	end_surplus;
	char	*aux_buf;

	i = pointer_endnl;
	while ((*stat_buf)[i])
		i++;
	end_surplus = i;
	aux_buf = (char *)malloc((end_surplus - pointer_endnl + 1) * sizeof(char));
	if (!aux_buf)
		return (-1);
	i = pointer_endnl - 1;
	while ((*stat_buf)[++i])
		aux_buf[i - pointer_endnl] = (*stat_buf)[i];
	free(*stat_buf);
	*stat_buf = aux_buf;
	return (1);
}
