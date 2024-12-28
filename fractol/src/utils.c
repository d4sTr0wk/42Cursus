/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:34:10 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/28 12:34:35 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_ishexdigit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

/* clean_exit:
*	Destroys the window, the MLX image and the MLX instance,
*	and frees the color palette, before ending the MLX loop
*	and destroying the display. Exits the process with the provided
*	exit code.
*/
void	clean_exit(int exit_code, t_fractol *fractol)
{
	if (!fractol)
		exit(exit_code);
	if (fractol->palette)
		free(fractol->palette);
	if (fractol->image)
		mlx_destroy_image(fractol->mlx, fractol->image);
	if (fractol->window && fractol->mlx)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(exit_code);
}

/* msg:
*	Displays an error message to the standard error.
*	Returns the provided error number.
*/
int	msg(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errno);
}

int	end_fractol(t_fractol *fractol)
{
	clean_exit(EXIT_SUCCESS, fractol);
	return (0);
}
