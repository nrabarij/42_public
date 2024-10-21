/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:24:31 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:25 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	*fdf_new_point(char *str, int *i, int xval, int yval)
{
	t_point	*p;

	if (!str || !str[*i])
		return (NULL);
	p = (t_point *)malloc(sizeof(t_point));
	if (p)
	{
		p->x = xval;
		p->y = yval;
		p->z = fdf_atoi(str, i, F_B10, 10);
		if (str[*i] == 44 && str[(*i) + 1] == 48 && str[(*i) + 2] == 120)
		{
			(*i) += 3;
			p->col = fdf_atoi(str, i, F_B16, 16);
		}
		else
			p->col = F_WHITE;
		p->prv = NULL;
		p->nxt = NULL;
		p->rgt = NULL;
		p->dwn = NULL;
		return (p);
	}
	perror(F_ER);
	return (NULL);
}

void	fdf_add_point(t_point **first, t_point *next)
{
	if (!next)
		return ;
	if (!(*first))
	{
		(*first) = next;
		(*first)->prv = (*first);
		(*first)->nxt = NULL;
		return ;
	}
	(*first)->prv->nxt = next;
	(*first)->prv->nxt->prv = (*first)->prv;
	(*first)->prv->nxt->nxt = NULL;
	(*first)->prv = (*first)->prv->nxt;
}

void	fdf_clr_point(t_point **p)
{
	if (!p || !(*p))
		return ;
	fdf_clr_point(&(*p)->nxt);
	free((*p));
	(*p) = NULL;
}

static void	fdf_origin(t_fdf *d, t_point *p)
{
	while (p)
	{
		p->ox = p->x;
		p->oy = p->y;
		p->oz = p->z;
		p->x = p->x - (d->mx / 2);
		p->y = p->y - (d->my / 2);
		p = p->nxt;
	}
}

void	fdf_link(t_fdf *d, t_point *p)
{
	t_point	*tmp;

	if (!p)
		return ;
	fdf_origin(d, p);
	while (p)
	{
		tmp = p->nxt;
		if (!(p->rgt) && tmp && tmp->x > p->x && tmp->y == p->y)
			p->rgt = tmp;
		while (tmp && tmp->x != p->x)
			tmp = tmp->nxt;
		if (!(p->dwn) && tmp && tmp->x == p->x && tmp->y > p->y)
			p->dwn = tmp;
		p = p->nxt;
	}
}
