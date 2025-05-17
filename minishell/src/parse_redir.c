/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:54:37 by maxgarci          #+#    #+#             */
/*   Updated: 2025/05/15 08:05:04 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_redir(char *str, int pos)
{
	return ((str[pos] == '>' && str[pos + 1] == '>') || str[pos] == '>'
		|| (str[pos] == '<' && str[pos + 1] == '<') || str[pos] == '<');
}

static int	handle_type_redir(char *str, int *pos, t_redir *redir)
{
	if (!redir)
		return (ft_putstr_fd(ENO_MEM_ERROR, 2), FN_FAILURE);
	if (str[*pos] == '>' && str[*pos + 1] == '>')
		redir->type = r_append;
	else if (str[*pos] == '>')
		redir->type = r_output;
	else if (str[*pos] == '<' && str[*pos + 1] == '<')
		redir->type = r_heredoc;
	else if (str[*pos] == '<')
		redir->type = r_input;
	else if (!char_is_valid(str[*pos + 2]))
		return (free(redir), ft_putstr_fd(PARSING_ERROR, 2), FN_FAILURE);
	while (is_redir(str, *pos))
		(*pos)++;
	while (ft_isspace(str[*pos]))
		(*pos)++;
	return (FN_SUCCESS);
}

static t_redir	*create_redir(char *str)
{
	int		i;
	char	*filename;
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	i = 0;
	if (handle_type_redir(str, &i, redir))
		return (NULL);
	filename = ft_strdup("");
	if (filename == NULL)
		return (ft_putstr_fd(ENO_MEM_ERROR, 2), free(redir), NULL);
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i++;
		else if (char_is_valid(str[i]))
			filename = strjoin_char(filename, str[i++]);
		else
			return (ft_putstr_fd(BAD_ASSIGNMENT_ERROR, 2), free(redir), NULL);
	}
	filename = strjoin_char(filename, '\0');
	redir->filename = filename;
	return (redir);
}

int	parse_redir(char *str, t_command **command, int *i, int *redir_pos)
{
	(*command)->redir[*redir_pos] = create_redir(str + (*i));
	if (!((*command)->redir[(*redir_pos)++]))
		return (PARSING);
	while (is_redir(str, (*i)))
		++(*i);
	while (ft_isspace(str[(*i)]))
		++(*i);
	while (str[(*i)] > ' ' && !is_redir(str, (*i)))
		++(*i);
	return (FN_SUCCESS);
}
