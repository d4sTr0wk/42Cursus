/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:54:46 by maxgarci          #+#    #+#             */
/*   Updated: 2023/10/13 22:17:42 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char const *s1);
int	ft_ftoa(double n);

#endif
