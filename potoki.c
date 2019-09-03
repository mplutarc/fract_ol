/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potoki.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:59:12 by mplutarc          #+#    #+#             */
/*   Updated: 2019/08/29 19:10:49 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*fractols(void *inc)
{
	t_fract		*fract;

	fract = (t_fract *)inc;
	if (fract->name == 'j')
		julia(fract);
	if (fract->name == 'm')
		mandelbrot(fract);
	else if (fract->name == 's')
		something(fract);
	else if (fract->name == 'b')
		buddhabrot(fract);
	else if (fract->name == 'k')
		korablik(fract);
	else if (fract->name == 'h')
		honeybadger(fract);
	return (NULL);
}

static void	freesomth(pthread_t *threads, t_fract *data)
{
	free(threads);
	free(data);
}

void		launch_fracts(t_fract *fract)
{
	pthread_t	*threads;
	t_fract		*data;
	int			step;
	int			i;

	step = HEIGHT / fract->pthreads + HEIGHT -
			HEIGHT / fract->pthreads * fract->pthreads;
	threads = (pthread_t *)ft_memalloc(sizeof(pthread_t) * fract->pthreads);
	data = (t_fract *)ft_memalloc(sizeof(t_fract) * fract->pthreads);
	i = -1;
	while (++i < fract->pthreads)
	{
		data[i] = *fract;
		data[i].ymin = step * i;
		data[i].ymax = step * (i + 1);
		pthread_create(&(threads[i]), NULL, fractols, &(data[i]));
	}
	i = -1;
	while (++i < fract->pthreads)
		pthread_join(threads[i], NULL);
	if (fract->name == 'b')
		buddhacolor(fract);
		freesomth(threads, data);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
							fract->img->img_ptr, 0, 0);
}
