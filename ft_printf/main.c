/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:41:41 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/11 01:04:53 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libc.h"
#include"ft_printf.c"
#include"ft_putchar.c"
#include"ft_putstr.c"
#include"ft_strlen.c"

int	main(void)
{
	int m = ft_printf("%s", "hola");
	printf("%i", m);
}
