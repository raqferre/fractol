/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:50:06 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 17:08:54 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	options(char *argv[])
{
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "julia")
		|| !ft_strcmp(argv[1], "julia_1")
		|| !ft_strcmp(argv[1], "julia_2"))
		return (0);
	return (1);
}

void	error_message(void)
{
	write(1, "Please choose your option:\n", 27);
	write(1, "mandelbrot, julia, julia_1 or julia_2\n", 39);
	exit(EXIT_FAILURE);
}

int	exit_when_close(void)
{
	exit(EXIT_FAILURE);
	return (0);
}
