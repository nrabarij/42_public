/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:09:06 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:40 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fdf_image(t_fdf *d)
{
	void	*tmp;

	tmp = mlx_new_image(d->mlx, F_WIDTH, F_HEIGHT);
	d->adr = mlx_get_data_addr(tmp, &d->bpp, &d->len, &d->end);
	fdf_draw(d);
	mlx_put_image_to_window(d->mlx, d->win, tmp, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
	d->img = tmp;
}

void	fdf_bresenham_line(t_fdf *d, double xy[6], char *dst, t_point *p)
{
	int	i[2];

	i[0] = (int)round(xy[4]);
	i[1] = (int)round(xy[5]);
	while (++(i[0]) < i[1])
	{
		xy[0] = (xy[0] + xy[2]);
		xy[1] = (xy[1] + xy[3]);
		if (round(xy[1]) + d->cam.yof >= 0
			&& round(xy[1]) + d->cam.yof < F_HEIGHT
			&& round(xy[0]) + d->cam.xof >= 0
			&& round(xy[0]) + d->cam.xof < F_WIDTH)
		{
			dst = d->adr + (int)((round(xy[1]) + d->cam.yof) * d->len)
				+ (int)((round(xy[0]) + d->cam.xof) * (d->bpp / 8));
			*(unsigned int *)dst = fdf_grad(i[0], i[1], p->col, p->rgt->col);
		}
	}
}

void	fdf_bresenham_column(t_fdf *d, double xy[6], char *dst, t_point *p)
{
	int	i[2];

	i[0] = (int)round(xy[4]);
	i[1] = (int)round(xy[5]);
	while (++(i[0]) < i[1])
	{
		xy[0] = (xy[0] + xy[2]);
		xy[1] = (xy[1] + xy[3]);
		if (round(xy[1]) + d->cam.yof >= 0
			&& round(xy[1]) + d->cam.yof < F_HEIGHT
			&& round(xy[0]) + d->cam.xof >= 0
			&& round(xy[0]) + d->cam.xof < F_WIDTH)
		{
			dst = d->adr + (int)((round(xy[1]) + d->cam.yof) * d->len)
				+ (int)((round(xy[0]) + d->cam.xof) * (d->bpp / 8));
			*(unsigned int *)dst = fdf_grad(i[0], i[1], p->col, p->dwn->col);
		}
	}
}
