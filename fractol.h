/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:38:58 by raqferre          #+#    #+#             */
/*   Updated: 2023/02/16 16:35:32 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define SIZE 800

# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*fractal;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		n;
	int		i;
	int		j;	

	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	re;
	double	im;
	double	temp;
	double	zoom;
}		t_data;

void	mandelbrot(t_data *f);
int		i_mandelbrot(t_data *f);
int		i_julia(char *argv, t_data *f);
void	julia(char *argv, t_data *f);
void	create_image(t_data *f);
void	create_window(t_data *f);
void	fractal_list(char *argv, t_data *f);
void	my_mlx_pixel_put(t_data *f, int x, int y, int color);
int		exit_when_close(void);
void	error_message(void);
int		ft_strcmp(char *s1, char *s2);
int		options(char *argv[]);
int		arrow_move(int keycode, t_data *f);
int		zoom(int keycode, int x, int y, t_data *f);
void	hooks(t_data *f);

#endif
