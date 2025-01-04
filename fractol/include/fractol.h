/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:58:52 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 19:09:50 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdlib.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 60
# define DISTANCE_MOVE 0.1
# define ZOOM_IN_FACTOR 0.5
# define ZOOM_OUT_FACTOR 2

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*buffer;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;

/*  Fractal Sets   */
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *fractol, double zr, double zi);
int		burning_ship(double cr, double ci);

/*  Draw Fractal	*/
void	draw_fractol(t_fractol *fractol);
int		julia_shift(int x, int y, t_fractol *fractol);
void	color_shift(t_fractol *f);

/*  Events   */
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

/* Initialization */
void	init_fractol(t_fractol *fractol);
void	init(t_fractol *fractol);
void	get_complex_layout(t_fractol *fractol);
double	ft_atof(char *str);

/*  Utils   */
int		ft_isspace(char c);
int		ft_ishexdigit(char c);
int		end_fractol(t_fractol *mlx);
void	clean_exit(int error_code, t_fractol *fractol);
int		msg(char *str1, char *str2, int errno);
void	help(t_fractol *fractol);
void	print_controls(void);

#endif
