/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:03:41 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 19:09:45 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

static int	key_event_redraw(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ONE && fractol->set != MANDELBROT)
		fractol->set = MANDELBROT;
	else if (keycode == KEY_TWO && fractol->set != JULIA)
		fractol->set = JULIA;
	else if (keycode == KEY_THREE && fractol->set != BURNING_SHIP)
		fractol->set = BURNING_SHIP;
	else
		return (1);
	get_complex_layout(fractol);
	draw_fractol(fractol);
	return (0);
}

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_UP)
		move(mlx, DISTANCE_MOVE, 'U');
	else if (keycode == KEY_DOWN)
		move(mlx, DISTANCE_MOVE, 'D');
	else if (keycode == KEY_LEFT)
		move(mlx, DISTANCE_MOVE, 'L');
	else if (keycode == KEY_RIGHT)
		move(mlx, DISTANCE_MOVE, 'R');
	else if (!key_event_redraw(keycode, mlx))
		return (1);
	else
		return (1);
	draw_fractol(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, ZOOM_IN_FACTOR);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, ZOOM_OUT_FACTOR);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	draw_fractol(mlx);
	return (0);
}
