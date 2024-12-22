/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:54:55 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/22 22:10:26 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

// EVENTS
# define CLOSE_BUTTON 17

typedef struct s_fractal {
	void *mlx;
	void *window;
	void *image;
	char *buffer;
	int		set;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
} t_fractal;

#endif
