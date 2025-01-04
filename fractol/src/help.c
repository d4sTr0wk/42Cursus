/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:59:53 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 18:46:21 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal_options(void)
{
	ft_putendl_fd("> Available Fractals", 1);
	ft_putendl_fd("Options", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol \
			<type>\n\t\t./fractol M\e[0m", 1);
	ft_putendl_fd("For Julia you can set initial values", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("> Controls", 1);
	ft_putendl_fd("Arrow keys\t\tmove view.", 1);
	ft_putendl_fd("Scroll wheel\t\tzoom in and out.", 1);
	ft_putendl_fd("Left click\t\tshift Julia set [Julia only].", 1);
	ft_putendl_fd("1, 2, 3\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract-ol.", 1);
}

void	help(t_fractol *f)
{
	ft_putendl_fd("| FRACT'OL |", 1);
	print_fractal_options();
	clean_exit(EXIT_FAILURE, f);
}
