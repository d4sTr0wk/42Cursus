/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   libft.h						:+:	 :+:	:+:   */
/*						      +:+ +:+	      +:+     */
/*   By: maxgarci <maxgarci@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/19 19:28:09 by maxgarci	       #+#    #+#	      */
/*   Updated: 2024/04/01 19:14:06 by maxgarci	      ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif
