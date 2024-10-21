/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:37:08 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:33:04 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	st_top(t_link **a, t_link **b, t_link *src, t_link *dst)
{
	int	psc;

	psc = 0;
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rr\n", TRUE);
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] == ((int *)src->data)[1])
		psc += ps_move(a, b, "ra\n", TRUE);
	while (((int *)(*a)->data)[1] == ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rb\n", TRUE);
	return (psc);
}

static int	st_bot(t_link **a, t_link **b, t_link *src, t_link *dst)
{
	int	psc;

	psc = 0;
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rrr\n", TRUE);
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] == ((int *)src->data)[1])
		psc += ps_move(a, b, "rra\n", TRUE);
	while (((int *)(*a)->data)[1] == ((int *)dst->data)[1]
		&& ((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rrb\n", TRUE);
	return (psc);
}

static int	st_rra_rb(t_link **a, t_link **b, t_link *src, t_link *dst)
{
	int	psc;

	psc = 0;
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1])
		psc += ps_move(a, b, "rra\n", TRUE);
	while (((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rb\n", TRUE);
	return (psc);
}

static int	st_ra_rrb(t_link **a, t_link **b, t_link *src, t_link *dst)
{
	int	psc;

	psc = 0;
	while (((int *)(*a)->data)[1] != ((int *)dst->data)[1])
		psc += ps_move(a, b, "ra\n", TRUE);
	while (((int *)(*b)->data)[1] != ((int *)src->data)[1])
		psc += ps_move(a, b, "rrb\n", TRUE);
	return (psc);
}

int	ps_rotate(t_link **a, t_link **b, t_link *src, t_link *dst)
{
	int	psc;
	int	s[2];

	if (!a || !(*a) || !b || !(b) || !src || !dst)
		return (0);
	psc = 0;
	s[0] = (int)(ft_link_size((*a)) / 2);
	s[1] = (int)(ft_link_size((*b)) / 2);
	if (((int *)src->data)[2] <= s[1] && ((int *)dst->data)[2] <= s[0])
		psc += st_top(a, b, src, dst);
	else if (((int *)src->data)[2] > s[1] && ((int *)dst->data)[2] > s[0])
		psc += st_bot(a, b, src, dst);
	else if (((int *)src->data)[2] <= s[1] && ((int *)dst->data)[2] > s[0])
		psc += st_rra_rb(a, b, src, dst);
	else if (((int *)src->data)[2] > s[1] && ((int *)dst->data)[2] <= s[0])
		psc += st_ra_rrb(a, b, src, dst);
	return (psc);
}
