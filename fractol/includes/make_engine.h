/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxgarci <maxgarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:27:08 by maxgarci          #+#    #+#             */
/*   Updated: 2024/12/04 10:27:08 by maxgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENGINE_H
# define MAKE_ENGINE_H

# include "fractal.h"

void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);

#endif  /* MAKE_ENGINE_H */
