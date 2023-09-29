/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:20:44 by maxgarci          #+#    #+#             */
/*   Updated: 2023/09/29 16:49:28 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_strstr

int	check_entire_word(char *str, char *to_find)
{
	int	found;
	int	count;

	found = 1;
	count = -1;
	while (found && to_find[++count] != '\0')
		if (str[count] != to_find[count])
			found = 0;
	return (found);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	found;

	found = 0;
	if (to_find[0] == '\0')
		return (str);
	while (*(str++) != '\0' && !found)
		if (*str == to_find[0])
			found = check_entire_word (str, to_find);
	if (found)
		return (str - 1);
	else
		return (0);
}
