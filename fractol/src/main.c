/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:39:36 by maxgarci          #+#    #+#             */
/*   Updated: 2024/08/19 23:37:29 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, 1920, 1080);
	while (1)
		;
	return (0);	
}
