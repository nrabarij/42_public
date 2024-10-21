/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 07:56:44 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:44 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	fdf_paddr(t_fdf *d, t_point *p, int code)
{
	int	addr;

	if (code == 'x')
	{
		addr = (((p->x * cos(d->cam.ang))
					- (p->y * sin(d->cam.ang))) * d->cam.zoom * cos(d->cam.y_a))
			+ ((p->z * (d->cam.zof)) * d->cam.zoom * sin(d->cam.y_a));
		return (addr);
	}
	else if (code == 'y')
	{
		addr = (((p->x * sin(d->cam.ang))
					+ (p->y * cos(d->cam.ang))) * d->cam.zoom * cos(d->cam.x_a))
			- ((p->z * (d->cam.zof)) * d->cam.zoom * sin(d->cam.x_a));
		return (addr);
	}
	return (-1);
}

static void	*fdf_draw_line(void *data)
{
	char	*dst;
	double	xy[6];
	t_fdf	*d;
	t_point	*p;

	d = (t_fdf *)data;
	p = d->map;
	dst = NULL;
	while (p)
	{
		if (p->rgt)
		{
			xy[0] = fdf_paddr(d, p, 'x');
			xy[1] = fdf_paddr(d, p, 'y');
			xy[2] = fdf_paddr(d, p->rgt, 'x') - fdf_paddr(d, p, 'x');
			xy[3] = fdf_paddr(d, p->rgt, 'y') - fdf_paddr(d, p, 'y');
			xy[5] = sqrt((xy[2] * xy[2]) + (xy[3] * xy[3]));
			xy[2] /= xy[5];
			xy[3] /= xy[5];
			xy[4] = 0;
			fdf_bresenham_line(d, xy, dst, p);
		}
		p = p->nxt;
	}
	return (NULL);
}

static void	*fdf_draw_column(void *data)
{
	char	*dst;
	double	xy[6];
	t_fdf	*d;
	t_point	*p;

	d = (t_fdf *)data;
	p = d->map;
	dst = NULL;
	while (p)
	{
		if (p->dwn)
		{
			xy[0] = fdf_paddr(d, p, 'x');
			xy[1] = fdf_paddr(d, p, 'y');
			xy[2] = fdf_paddr(d, p->dwn, 'x') - fdf_paddr(d, p, 'x');
			xy[3] = fdf_paddr(d, p->dwn, 'y') - fdf_paddr(d, p, 'y');
			xy[5] = sqrt((xy[2] * xy[2]) + (xy[3] * xy[3]));
			xy[2] /= xy[5];
			xy[3] /= xy[5];
			xy[4] = 0;
			fdf_bresenham_column(d, xy, dst, p);
		}
		p = p->nxt;
	}
	return (NULL);
}

static void	*fdf_draw_point(void *data)
{
	int		x;
	int		y;
	char	*dst;
	t_fdf	*d;
	t_point	*p;

	d = (t_fdf *)data;
	p = d->map;
	while (p)
	{
		x = fdf_paddr(d, p, 'x');
		y = fdf_paddr(d, p, 'y');
		if ((x + d->cam.xof >= 0) && (x + d->cam.xof < F_WIDTH)
			&& (y + d->cam.yof >= 0) && (y + d->cam.yof < F_HEIGHT))
		{
			dst = d->adr + (int)(((y) + d->cam.yof) * d->len)
				+ (int)(((x) + d->cam.xof) * (d->bpp / 8));
			*(unsigned int *)dst = p->col;
		}
		p = p->nxt;
	}
	return (NULL);
}

void	*fdf_draw(void *data)
{
	fdf_draw_point(data);
	fdf_draw_line(data);
	fdf_draw_column(data);
	return (NULL);
}
