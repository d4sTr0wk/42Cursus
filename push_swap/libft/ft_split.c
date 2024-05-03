/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:53:18 by maxgarci          #+#    #+#             */
/*   Updated: 2023/11/22 21:38:50 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	cnt;

	if (!s)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			++cnt;
		i++;
	}
	return (cnt);
}

char	*word_allocation(char const *s, int start, int end)
{
	char	*word;
	int		index;

	word = (char *)malloc(((end - start) + 2) * sizeof(char));
	if (!word)
		return (NULL);
	index = 0;
	while (end >= start)
		word[index++] = s[start++];
	word[index] = '\0';
	return (word);
}

void	initialize(int *i, int *pos_array, int *start)
{
	*i = -1;
	*pos_array = 0;
	*start = -1;
}

char	**free_memory(char **array_split, int tam)
{
	int	i;

	i = 0;
	while (i < tam)
		free(array_split[i++]);
	free(array_split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array_split;
	int		i;
	int		pos_array;
	int		start;

	array_split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array_split)
		return (NULL);
	initialize(&i, &pos_array, &start);
	while (s != NULL && s[++i])
	{
		if ((s[i] != c) && (start == -1))
			start = i;
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
		{
			array_split[pos_array++] = word_allocation(s, start, i);
			if (!array_split[pos_array - 1])
				return (free_memory(array_split, pos_array));
			start = -1;
		}
	}
	array_split[pos_array] = NULL;
	return (array_split);
}
