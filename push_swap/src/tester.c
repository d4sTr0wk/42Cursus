/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:29 by maxgarci          #+#    #+#             */
/*   Updated: 2024/03/01 00:45:15 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

int	search_num(int num, int *num_list)
{
	int	i;

	i = 0;
	while (num_list[i])
	{
		if (num_list[i] == num)
			return (1);
		i++;
	}
	num_list[i] = num;
	return (0);
}

int main(int argc, char *argv[])
{
	int	cnt_num, num;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cnt_num = ft_atoi(argv[1]);
	int num_list[cnt_num];
	srand(getpid());
	while (cnt_num--)
	{
		num = rand() % 100 + 1;
		printf("%d ", num);
	}
	return (0);
}
