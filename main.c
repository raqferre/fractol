/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:37:42 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 16:38:54 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_data *f)
{
	mlx_key_hook(f->mlx_win, arrow_move, f);
	mlx_hook(f->mlx_win, 17, 0, exit_when_close, f);
	mlx_mouse_hook(f->mlx_win, zoom, f);
}

void	create_window(t_data *f)
{
	f->mlx = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx, SIZE, SIZE, "FRACTOL");
}

void	create_image(t_data *f)
{
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
}

void	fractal_list(char *argv, t_data *f)
{
	if (!ft_strcmp(argv, "julia") || !ft_strcmp(argv, "julia_1")
		|| !ft_strcmp(argv, "julia_2"))
	{
		julia(argv, f);
		f->fractal = argv;
	}
	else if (!ft_strcmp(argv, "mandelbrot"))
	{
		mandelbrot(f);
		f->fractal = argv;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_data	f;

	if (argc != 2 || options(argv))
		error_message();
	f.zoom = 4.0;
	create_window(&f);
	create_image(&f);
	fractal_list(argv[1], &f);
	hooks(&f);
	mlx_loop(f.mlx);
	return (0);
}
