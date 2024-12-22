/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:24:45 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/22 22:27:34 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void msg()
{
	ft_printf("\nfractal: parameters error\n");
}

void clean_init(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->window = NULL;
	fractal->image = NULL;
	fractal->buffer = NULL;
	fractal->set = -1;
}

void clean_fractal(int errno, t_fractal *fractal)
{
	if (!fractal)
		exit(errno);
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window && fractal->mlx)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(errno);
}

void init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		clean_fractal(1, fractal);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractal->window)
		clean_fractal(1, fractal);
	
}

int	close_fractal(t_fractal *fractal)
{
	clean_fractal(0, fractal);
	return (0);
}

void calculate_mandelbrot(t_fractal *fractal)
{
	int i;
	double x_temp;

	fractal->set = MANDELBROT;
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
}

int	draw_fractal(t_fractal *fractal, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image,0, 0);
	return (0);	
}

int main(int argc, char **argv)
{
	t_fractal fractal;

	(void) argv;
	if (argc < 2)
		msg();
	clean_init(&fractal);
	init(&fractal);
	draw_fractal(fractal, 0, 0);
	mlx_hook(fractal.window, CLOSE_BUTTON, 0, close_fractal, &fractal);
	mlx_loop(fractal.mlx);
}
