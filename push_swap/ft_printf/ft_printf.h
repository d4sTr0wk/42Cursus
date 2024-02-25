/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:24:53 by maxgarci          #+#    #+#             */
/*   Updated: 2024/01/28 23:24:53 by maxgarci         ###   ########.fr       */
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
int		ft_putnbr(long nbr);
int		ft_puthex(char c, unsigned long long hex);
int		ft_putptr(unsigned long long ptr);
size_t	ft_strlen(const char *str);

#endif
