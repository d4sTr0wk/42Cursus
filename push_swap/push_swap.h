/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:20:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/29 11:45:23 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int	main(int argc, char **argv);
int	initialize_args(int argc, char **argv, t_stack **a);

int	ft_atoi(const char *nptr, int *error);

t_stack *ft_lstnew(int value);
void    ft_lstadd_back(t_stack **lst, t_stack *new);

#endif
