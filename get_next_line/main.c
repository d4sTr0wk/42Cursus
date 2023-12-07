/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:26:22 by maxgarci          #+#    #+#             */
/*   Updated: 2023/12/07 16:37:10 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	FILE	*file;
	char	*line;

	file = fopen("files/41_with_nl", "r");
	if (!file)
		return (-1);

	while ((line = get_next_line(fileno(file))) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	fclose(file);
	return (0);
}
