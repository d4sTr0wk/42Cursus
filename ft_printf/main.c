/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:41:41 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 19:16:05 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf.c"
#include"ft_putchar.c"
#include"ft_putstr.c"
#include"ft_strlen.c"

int	main(void)
{
	int m1 = ft_printf("%s%%\n", "hola");
	int m2 = printf("%s%%\n", "hola");
	printf("%i ", m1);
	printf("%i", m2);
}
