/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:54:46 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/18 20:34:57 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_ftoa(double n);
int     ft_itoa(int n);
int     ft_hex(char c, int hex);
size_t	ft_strlen(const char *str);

#endif
