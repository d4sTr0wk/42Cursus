/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:41:41 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 23:37:34 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf.c"
#include"ft_putchar.c"
#include"ft_putstr.c"
#include"ft_strlen.c"
#include"ft_itoa.c"
#include"ft_strdup.c"
#include"ft_ftoa.c"

int	main(void)
{
	int m1 = ft_printf("%d\n", 12.45077799999);
	int m2 = printf("%f\n", 12.450777999999);
	printf("%i ", m1);
	printf("%i", m2);
}
