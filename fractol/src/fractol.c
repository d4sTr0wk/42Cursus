/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:45:33 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 18:31:46 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_set(t_fractol *fractol, char **av)
{
	if (av[1][0] == 'M' && av[1][1] == '\0')
		fractol->set = MANDELBROT;
	else if (av[1][0] == 'J' && av[1][1] == '\0')
		fractol->set = JULIA;
	else if (av[1][0] == 'B' && av[1][1] == '\0')
		fractol->set = BURNING_SHIP;
	else
		help(fractol);
}

static void	get_julia_starting_values(t_fractol *fractol, int ac, char **av)
{
	if (fractol->set != JULIA || ac == 2)
	{
		fractol->kr = -0.7;
		fractol->ki = 0;
		return ;
	}
	if (ac == 3)
		help(fractol);
	if (!ft_strchr(av[2], '.'))
		help(fractol);
	if (!ft_strchr(av[3], '.'))
		help(fractol);
	fractol->kr = ft_atof(av[2]);
	fractol->ki = ft_atof(av[3]);
	if (fractol->kr > 2.0 || fractol->kr < -2.0)
		help(fractol);
	if (fractol->ki >= 2.0 || fractol->ki <= -2.0)
		help(fractol);
}

static void	handle_args(t_fractol *fractol, int ac, char **av)
{
	get_set(fractol, av);
	if (fractol->set != JULIA && ac > 3)
		help(fractol);
	else if (fractol->set == JULIA && ac > 5)
		help(fractol);
	get_julia_starting_values(fractol, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
		help(NULL);
	init_fractol(&fractol);
	handle_args(&fractol, ac, av);
	init(&fractol);
	draw_fractol(&fractol);
	print_controls();
	mlx_hook(fractol.window, EVENT_CLOSE_BTN, 0, end_fractol, &fractol);
	mlx_key_hook(fractol.window, key_event, &fractol);
	mlx_mouse_hook(fractol.window, mouse_event, &fractol);
	mlx_loop(fractol.mlx);
}
