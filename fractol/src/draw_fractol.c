/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:17:47 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/28 11:19:17 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
*/
static void	set_pixel_color(t_fractol *fractol, int x, int y, int color)
{
		fractol->buffer[x * 4 + y * WIDTH * 4] = color;
		fractol->buffer[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		fractol->buffer[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		fractol->buffer[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/* calculate_fractal:
*	Picks the correct fractal calculation function depending
*	on the current fractal set.
*/
static int	calculate_fractal(t_fractol *fractol, double pr, double pi)
{
	int	nb_iter;

	if (fractol->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (fractol->set == JULIA)
		nb_iter = julia(fractol, pr, pi);
	else if (fractol->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	return (nb_iter);
}

void	draw_fractol(t_fractol *fractol)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(fractol->mlx, fractol->window);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = fractol->min_r + (double)x * (fractol->max_r - fractol->min_r) / WIDTH;
			pi = fractol->max_i + (double)y * (fractol->min_i - fractol->max_i) / HEIGHT;
			nb_iter = calculate_fractal(fractol, pr, pi);
			set_pixel_color(fractol, x, y, fractol->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0, 0);
}
