/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:37:34 by mcombeau          #+#    #+#             */
/*   Updated: 2024/12/28 11:21:57 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* julia_shift:
*	Changes the Julia calculation kr and ki values to get a different Julia
*	fractal shape. This function should be called when the user clicks on
*	a point on the sceen.
*/
int	julia_shift(int x, int y, t_fractol *fractol)
{
	fractol->kr = fractol->min_r + (double)x * (fractol->max_r - fractol->min_r) / WIDTH;
	fractol->ki = fractol->max_i + (double)y * (fractol->min_i - fractol->max_i) / HEIGHT;
	draw_fractol(fractol);
	return (0);
}

/* julia:
*	Checks whether a complex number is part of the Julia set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Julia set, which can then be used to determine coloring.
*/
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
/*
	How it works:

	The Julia set is closely related to the Mandelbrot set:
	its formula is identical. What differs are the complex
	number we plug into it.
	
	Mandelbrot uses 0 as a starting value for zr and zi, and
	adds pixel coordinates (cr and ci) every time it iterates.

	On the other hand, Julia starts with pixel coordinates as
	zr and zi and adds another complex number (kr and ki) every time
	it iterates.

	kr and ki values determine the shape Julia will take on.
	If kr + ki is part of the Mandelbrot set, Julia will be a continuous
	solid shape. If kr + ki is not part of the Mandelbrot set, the
	Julia fractal will be a disconnected set of separate islands.
	If kr + ki is a point that is close to the Mandelbrot fractal boundary,
	the same patterns we see at that point in the Mandelbrot fractal
	will emerge in the Julia fractal.
*/
