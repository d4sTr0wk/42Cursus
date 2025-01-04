/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:37:06 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 19:11:49 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->image = NULL;
	fractol->buffer = NULL;
	fractol->set = -1;
	fractol->min_r = 0;
	fractol->max_r = 0;
	fractol->min_i = 0;
	fractol->max_i = 0;
	fractol->kr = 0;
	fractol->ki = 0;
	fractol->sx = 0;
	fractol->rx = 0;
	fractol->fx = 0;
	fractol->palette = NULL;
	fractol->color_pattern = -1;
	fractol->color = 0x9966FF;
}

/* get_complex_layout:
*	Maps the complex number axes to the window width and height to
*	create an equivalence between a given pixel and a complex number.
*		- The Mandelbox set real and imaginary axes range from 4 to -4
*		so the edges are mapped to those numbers for the fractal to appear
*		centered.
*		- Julia needs a bit more space to the right than Mandelbrot or
*		Burning Ship, so the mapping must also be shifted slightly.
*	Also, one of the edges is always calculated according to the other edges
*	to avoid fractal distortion if the window proportions change.
*/
void	get_complex_layout(t_fractol *fractol)
{
	if (fractol->set == JULIA)
	{
		fractol->min_r = -2.0;
		fractol->max_r = 2.0;
		fractol->min_i = -2.0;
		fractol->max_i = fractol->min_i + \
			(fractol->max_r - fractol->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		fractol->min_r = -2.0;
		fractol->max_r = 1.0;
		fractol->max_i = -1.5;
		fractol->min_i = fractol->max_i + \
			(fractol->max_r - fractol->min_r) * HEIGHT / WIDTH;
	}
}

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), fractol);
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->window)
		clean_exit(msg("MLX: error creating window.", "", 1), fractol);
	fractol->sx = 2.0;
	fractol->rx = 0.5;
	fractol->fx = 1.0;
	get_complex_layout(fractol);
	color_shift(fractol);
}
