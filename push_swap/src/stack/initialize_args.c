/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:46:29 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/18 20:12:01 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_args(int argc, char **argv, t_stk **a)
{
	int		args_splitted;
	char	**args;

	if ((argc == 2 && argv[1][0] == '\0') || argc == 1)
		return (1);
	args = create_args(&argc, argv, &args_splitted);
	if (check_args(args, argc))
	{
		if (args_splitted)
			free_args(args, argc);
		return (1);
	}
	if (add_elems_stk(a, argc, args))
	{
		if (args_splitted)
			free_args(args, argc);
		return (1);
	}
	assign_index(a);
	if (args_splitted)
		free_args(args, argc);
	return (0);
}
