/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:46 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:37 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	fdf_init_view(t_fdf *d)
{
	double	zoom;

	d->cam.xof = (F_WIDTH / 2);
	d->cam.yof = (F_HEIGHT / 2);
	d->cam.zof = 1;
	d->cam.zoom = 1;
	zoom = sqrt(pow(d->mx, 2) + pow(d->my, 2)) * 1.5;
	while (zoom * (d->cam.zoom + 0.5) < F_WIDTH
		&& zoom * (d->cam.zoom + 0.5) < F_HEIGHT)
		(d->cam.zoom) += 0.5;
	d->cam.ang = 0.75;
	d->cam.x_a = 1.10;
	d->cam.y_a = 0;
}

static int	fdf_init_map(t_fdf *d, int fd)
{
	d->map = fdf_parse(d, fd);
	if (!d->map)
		return (fdf_free(d), 1);
	fdf_init_view(d);
	d->mlx = mlx_init();
	if (!d->mlx)
		return (perror(F_ER), fdf_free(d), 1);
	d->win = mlx_new_window(d->mlx, F_WIDTH, F_HEIGHT, F_TITLE);
	if (!d->win)
		return (perror(F_ER), fdf_free(d), 1);
	d->img = mlx_new_image(d->mlx, F_WIDTH, F_HEIGHT);
	if (!d->img)
		return (perror(F_ER), fdf_free(d), 1);
	d->adr = mlx_get_data_addr(d->img, &d->bpp, &d->len, &d->end);
	if (!d->adr)
		return (perror(F_ER), fdf_free(d), 1);
	fdf_draw((void *)d);
	return (0);
}

int	fdf_init(t_fdf *d, int fd)
{
	if (fdf_init_map(d, fd))
		return (1);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	fdf_ctrl(d);
	mlx_loop(d->mlx);
	return (0);
}
