/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:23:59 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:32:19 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	st_rpos(t_link *p)
{
	if (((int *)p->data)[1] == 0)
	{
		if (((int *)p->prev->data)[1] == ((int)ft_link_size(p) - 1)
			&& ((int *)p->next->data)[1] == 1)
			return (TRUE);
	}
	else if (((int *)p->data)[1] > 0
			&& ((int *)p->data)[1] < ((int)ft_link_size(p) - 1))
	{
		if (((int *)p->prev->data)[1] == ((int *)p->data)[1] - 1
			&& ((int *)p->next->data)[1] == ((int *)p->data)[1] + 1)
			return (TRUE);
	}
	else if (((int *)p->data)[1] == ((int)ft_link_size(p) - 1))
	{
		if (((int *)p->prev->data)[1] == ((int *)p->data)[1] - 1
			&& ((int *)p->next->data)[1] == 0)
			return (TRUE);
	}
	return (FALSE);
}

static int	st_prio(t_link *p, size_t size)
{
	size_t	i;
	size_t	j;
	t_link	*tmp;

	i = -1;
	j = -1;
	tmp = p;
	while (++i < size)
	{
		if (((int *)tmp->data)[0] > ((int *)tmp->next->data)[0])
			break ;
		tmp = tmp->next;
	}
	tmp = p->prev;
	while (++j < size)
	{
		if (((int *)tmp->data)[0] < ((int *)tmp->prev->data)[0])
			break ;
		tmp = tmp->prev;
	}
	if (i <= j)
		return (1);
	if (i > j)
		return (2);
	return (0);
}

static int	st_sort(t_link *p, size_t size)
{
	if (size < 2)
		return (FALSE);
	while (--size)
	{
		if (((int *)p->data)[0] > ((int *)p->next->data)[0])
			return (TRUE);
		p = p->next;
	}
	return (FALSE);
}

int	ps_solve(t_link **a, t_link **b, size_t size)
{
	int	psc;

	psc = 0;
	if (size == 3)
		return (ps_three(a, TRUE));
	while (st_rpos((*a)) && ((int *)(*a)->data)[1])
	{
		if (st_prio((*a), size) == 1)
			psc += ps_move(a, b, "ra\n", TRUE);
		else if (st_prio((*a), size) == 2)
			psc += ps_move(a, b, "rra\n", TRUE);
	}
	if (st_sort((*a), size))
		psc += ps_algo(a, b, ft_link_size((*a)));
	while (st_rpos((*a)) && ((int *)(*a)->data)[1])
	{
		if (st_prio((*a), size) == 1)
			psc += ps_move(a, b, "ra\n", TRUE);
		else if (st_prio((*a), size) == 2)
			psc += ps_move(a, b, "rra\n", TRUE);
	}
	if (st_sort((*a), size))
		return (-1);
	return (psc);
}
