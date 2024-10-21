/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_memo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:46 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:32 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_fdf	*fdf_alloc(int fd)
{
	t_fdf	*d;

	d = (t_fdf *)malloc(sizeof(t_fdf));
	if (!d)
	{
		perror(F_ER);
		fdf_close(fd);
		exit(1);
	}
	d->mx = 0;
	d->my = 0;
	d->bpp = 0;
	d->end = 0;
	d->len = 0;
	d->adr = NULL;
	d->img = NULL;
	d->map = NULL;
	d->mlx = NULL;
	d->win = NULL;
	return (d);
}

void	fdf_free(t_fdf *d)
{
	if (d)
	{
		if (d->map)
			fdf_clr_point(&(d->map));
		if (d->mlx)
		{
			if (d->img)
				mlx_destroy_image(d->mlx, d->img);
			if (d->win)
				mlx_destroy_window(d->mlx, d->win);
			mlx_destroy_display(d->mlx);
			free(d->mlx);
		}
		free(d);
	}
}

static int	fdf_exit(t_fdf *d)
{
	fdf_free(d);
	exit(0);
}

int	fdf_ctrl(t_fdf *d)
{
	mlx_hook(d->win, 17, 0, &fdf_exit, d);
	mlx_hook(d->win, 2, 1L << 0, &fdf_key, d);
	return (0);
}
