/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:14:39 by maxgarci          #+#    #+#             */
/*   Updated: 2025/02/06 01:11:03 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int main(int argc, char **argv) 
{
	if (argc <= 4)
		return (print_error(ARGS_NUM_ERROR));
	printf("%s", argv[0]);
	printf("Todo ha ido genial");

	return (0);
}
