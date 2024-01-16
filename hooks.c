/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:12:28 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 16:44:52 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arrow_move(int keycode, t_data *f)
{
	if (keycode == ESC_KEY)
		exit(EXIT_FAILURE);
	if (keycode == LEFT_KEY)
		f->x += 0.1;
	if (keycode == RIGHT_KEY)
		f->x -= 0.1;
	if (keycode == UP_KEY)
		f->y += 0.1;
	if (keycode == DOWN_KEY)
		f->y -= 0.1;
	mlx_clear_window(f->mlx, f->mlx_win);
	if (!ft_strcmp(f->fractal, "mandelbrot"))
		mandelbrot(f);
	if (!ft_strcmp(f->fractal, "julia") || !ft_strcmp(f->fractal, "julia_1")
		|| !ft_strcmp(f->fractal, "julia_2"))
		julia(f->fractal, f);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, f->x, f->y);
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *f)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN || keycode == MOUSE_UP)
	{
		if (keycode == MOUSE_DOWN)
			f->zoom /= 0.8;
		else
			f->zoom *= 0.8;
	}
	mlx_clear_window(f->mlx, f-> mlx_win);
	if (!ft_strcmp(f->fractal, "julia") || !ft_strcmp(f->fractal, "julia_1")
		|| !ft_strcmp(f->fractal, "julia_2"))
		julia(f->fractal, f);
	if (!ft_strcmp(f->fractal, "mandelbrot"))
		mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	return (0);
}
