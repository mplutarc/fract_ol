/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:45:46 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 18:51:59 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coord		cocoords(t_complex p, t_fract *fract)
{
	t_coord poi;

	poi.x = (int)(p.re * (0.5 * fract->scale * WIDTH) - fract->offset_x
					+ WIDTH / 2);
	poi.y = (int)(p.im * 0.5 * fract->scale * HEIGHT) - fract->offset_y
					+ HEIGHT / 2;
	return (poi);
}

t_complex	coords(t_coord point, t_fract *fract)
{
	t_complex	p;

	p.re = (double)(point.x - (WIDTH / 2) + fract->offset_x) / ((HEIGHT / 2)
						* fract->scale);
	p.im = (double)(point.y - (HEIGHT / 2) + fract->offset_y) / ((HEIGHT / 2)
						* fract->scale);
	return (p);
}

void		events(t_fract fract)
{
	mlx_hook(fract.win_ptr, 2, 0, keypress, &fract);
	mlx_hook(fract.win_ptr, 4, 0, mousezoom, &fract);
	mlx_hook(fract.win_ptr, 17, 0, ft_close, &fract);
	mlx_hook(fract.win_ptr, 6, 0, mousemove, &fract);
	mlx_hook(fract.win_ptr, 5, 0, mouserelease, &fract);
}

void		put(t_fract *fract)
{
	fract->scale = 0.7;
	fract->offset_x = 2;
	fract->offset_y = 0;
	fract->flags = 0;
	fract->pthreads = 8;
	fract->number = 0;
	fract->name = 'm';
	fract->mirror = 1;
	fract->fractol.c_re = -0.5;
	fract->fractol.c_im = 0.5;
	fract->maxiter = MAX_ITER;
	fract->mass = (int *)ft_memalloc(sizeof(int) * WIDTH * HEIGHT);
}

int			main(int ag, char **ac)
{
	t_fract		fract;
	t_img		*img;

	img = (t_img *)ft_memalloc(sizeof(t_img));
	fract.mlx_ptr = mlx_init();
	fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIDTH, HEIGHT, "EBALA");
	img->width = WIDTH;
	img->height = HEIGHT;
	img->img_ptr = mlx_new_image(fract.mlx_ptr, img->width, img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp,
						&img->size_line, &img->endian);
	img->bpp /= 8;
	fract.img = img;
	put(&fract);
	events(fract);
	launch_fracts(&fract);
	mlx_loop(fract.mlx_ptr);
}
