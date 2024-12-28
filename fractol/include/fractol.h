/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:58:52 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/28 15:12:42 by maxgarci         ###   ########.fr       */
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
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 20

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

/* Colors	*/
void	color_shift(t_fractol *fractol);
void	set_color_mono(t_fractol *fractol, int color);
void	set_color_multiple(t_fractol *fractol, int colors[4], int n);
void	set_color_zebra(t_fractol *fractol, int color);
void	set_color_triad(t_fractol *fractol, int color);
void	set_color_tetra(t_fractol *fractol, int color);
void	set_color_opposites(t_fractol *fractol, int color);
void	set_color_contrasted(t_fractol *fractol, int color);
void	set_color_graphic(t_fractol *fractol, int color);
int		get_percent_color(int color, double percent);

/*  Events   */
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

/* Initialization */
void	init_fractol(t_fractol *fractol);
void	reinit_img(t_fractol *fractol);
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
