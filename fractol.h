/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:47:05 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 17:25:58 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "math.h"
# include "libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <stdio.h>
# define WIDTH 1800
# define HEIGHT 1600
# define MAX_ITER 50

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_coord
{
	int			prevx;
	int			prevy;
	int			x;
	int			y;
}				t_coord;

typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct	s_img
{
	void		*img_ptr;
	void		*data_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_fractol
{
	double		c_im;
	double		c_re;
	double		old_re;
	double		old_im;
	double		new_re;
	double		new_im;
	int			iter;
	int			color;
}				t_fractol;

typedef struct	s_fract
{
	t_img		*img;
	t_coord		*point;
	t_complex	c;
	t_coord		mouse;
	t_fractol	fractol;
	void		*mlx_ptr;
	void		*win_ptr;
	double		scale;
	int			*map;
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	int			flags;
	int			ymin;
	int			ymax;
	int			pthreads;
	char		name;
	int			maxiter;
	int			number;
	int			mirror;
	int			*mass;
}				t_fract;

t_complex		coords(t_coord point, t_fract *fract);
t_coord			cocoords(t_complex p, t_fract *fract);
int				keypress(int but, void *tmp);
int				ft_close(void *param);
int				mousezoom(int but, int x, int y, void *tmp);
void			new_pxl(t_coord p, t_img *img, unsigned int clolr);
void			mandelbrot(t_fract *fract);
int				mousemove(int x, int y, void *tmp);
int				mouserelease(int but, int x, int y, void *tmp);
void			launch_fracts(t_fract *fract);
int				color(t_fract *fract, int iter);
void			julia(t_fract *fract);
void			something(t_fract *fract);
void			korablik(t_fract *fract);
void			honeybadger(t_fract *fract);
void			buddhabrot(t_fract *fract);
void			buddhacolor(t_fract *fract);

#endif
