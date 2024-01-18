/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:14:37 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/18 20:37:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int recursive_hex(char *dic, int hex, int cnt)
{
    if (hex > 15)
    {
        cnt += recursive_hex(dic, (hex / 16), cnt);
        cnt += ft_putchar(*(dic + (hex % 16)));
    }
    else
        return (ft_putchar(*(dic + hex)));
    return (0);
}

int ft_hex(char c, int hex)
{
        char    *dictionary;
        if (c == 'x')
            dictionary = "0123456789abcdef";
        else
            dictionary = "0123456789ABCDEF";
        return (recursive_hex(dictionary, hex, 0));
}