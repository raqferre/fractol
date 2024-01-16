/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:59:47 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 16:40:12 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	i_julia(char *argv, t_data *f)
{
	if (!ft_strcmp(argv, "julia_1"))
	{
		f->c_re = 0.468;
		f->c_im = 0.387;
	}
	else if (!ft_strcmp(argv, "julia_2"))
	{
		f->c_re = 0.632;
		f->c_im = 0.566;
	}
	else
	{
		f->c_re = 0.592;
		f->c_im = 0.348;
	}
	while (f->n < 100 && f->re * f->re + f->im * f->im < 4)
	{
		f->temp = f->re * f->re - f->im * f->im;
		f->im = 2 * f->re * f->im + f->c_re;
		f->re = f->temp + f->c_im;
		f->n++;
	}
	return (f->n);
}

void	julia(char *argv, t_data *f)
{
	f->i = 0;
	while (f->i < SIZE)
	{
		f->j = 0;
		while (f->j < SIZE)
		{
			f->n = 0;
			f->re = (f->i - SIZE / 2) * (f->zoom / SIZE) + f->x;
			f->im = (f->j - SIZE / 2) * (f->zoom / SIZE) + f->y;
			if (f->n < 100)
				my_mlx_pixel_put(f, f->i, f->j, i_julia(argv, f) * 0x0e2433);
			f->j++;
		}
		f->i++;
	}
}
