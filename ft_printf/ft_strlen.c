/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:02:01 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/11 01:02:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libc.h"

size_t  ft_strlen(const char *str)
{
        int     cnt;

        cnt = 0;
        while (*(str + (cnt)) != '\0')
                ++cnt;
        return ((size_t)cnt);
}
