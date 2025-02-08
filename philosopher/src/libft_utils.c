/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:39:16 by maxgarci          #+#    #+#             */
/*   Updated: 2025/02/08 22:27:35 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + (cnt)) != '\0')
		++cnt;
	return ((size_t)cnt);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		sign = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = (str[i++] - '0') + num * 10;
	return ((unsigned)num * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &(s[i]), 1);
}
