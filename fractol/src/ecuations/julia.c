/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:56:22 by maxgarci          #+#    #+#             */
/*   Updated: 2025/01/04 18:26:15 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_fractol *fractol)
{
	fractol->kr = fractol->min_r + (double)x * \
		(fractol->max_r - fractol->min_r) / WIDTH;
	fractol->ki = fractol->max_i + (double)y * \
		(fractol->min_i - fractol->max_i) / HEIGHT;
	draw_fractol(fractol);
	return (0);
}

int	julia(t_fractol *fractol, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + fractol->ki;
		zr = zr * zr - zi * zi + fractol->kr;
		zi = tmp;
		n++;
	}
	return (n);
}
