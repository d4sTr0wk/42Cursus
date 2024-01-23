/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:09:51 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/23 20:46:00 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	return (write(1, "0x", 2) + ft_puthex('p', ptr));
}

size_t	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + (cnt)) != '\0')
		++cnt;
	return ((size_t)cnt);
}
