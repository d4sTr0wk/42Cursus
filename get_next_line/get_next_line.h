/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:09:01 by maxgarci          #+#    #+#             */
/*   Updated: 2023/12/09 01:04:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_file(char **stat_buf, char *buf, int fd);
int		ft_strlen(const char *str);
void	ft_strcpy(char **dst, const char *src);
int		strjoin_buf(char **stat_buf, char *buf, ssize_t read_bytes);
int		newline(char **stat_buf, char **ln, int point_nl_seek, int look_for_nl);
int		delete_newline(char **stat_buf, int pointer_endnl);

#endif
