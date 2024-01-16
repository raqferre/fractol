/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:16:29 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 16:35:16 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	i_mandelbrot(t_data *f)
{
	f->c_re = (f->i - SIZE / 2.0) * f->zoom / SIZE + f->x;
	f->c_im = (f->j - SIZE / 2.0) * f->zoom / SIZE + f->y;
	while (f->n < 100 && f->re * f->re + f->im * f->im < 4)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im = 2 * f->re * f->im + f->c_im;
		f->re = f->temp;
		f->n++;
	}
	return (f->n);
}

void	mandelbrot(t_data *f)
{
	f->i = 0;
	while (f->i < SIZE)
	{
		f->j = 0;
		while (f->j < SIZE)
		{
			f->n = 0;
			f->re = 0;
			f->im = 0;
			if (f->n < 100)
				my_mlx_pixel_put(f, f->i, f->j, i_mandelbrot(f) * 0x0e2433);
			f->j++;
		}
		f->i++;
	}
}
