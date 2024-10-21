/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:43:36 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:32:47 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	st_chunk(t_link *a, size_t size)
{
	int	chunk[3];

	chunk[1] = INT_MAX;
	chunk[2] = INT_MIN;
	while (size--)
	{
		if (((int *)a->data)[6] > chunk[2])
			chunk[2] = ((int *)a->data)[6];
		if (((int *)a->data)[6] < chunk[1])
			chunk[1] = ((int *)a->data)[6];
		a = a->next;
	}
	if (chunk[1] != chunk[2])
		chunk[0] = chunk[1] + 1;
	else if (chunk[1] == chunk[2])
		chunk[0] = chunk[1];
	return (chunk[0]);
}

static int	st_psh(t_link **a, t_link **b, int max)
{
	int	psc;

	psc = 0;
	if (ft_link_size((*b)) < 2)
		psc += ps_move(a, b, "pb\n", TRUE);
	else if (ft_link_size((*b)) > 1)
	{
		if (((int *)(*b)->data)[6] % 2 >= 1
			&& ((int *)(*b)->data)[6] < max)
		{
			psc += ps_move(a, b, "rb\n", TRUE);
			psc += ps_move(a, b, "pb\n", TRUE);
		}
		else if (((int *)(*b)->data)[6] % 2 == 0
			|| (((int *)(*b)->data)[6] % 2 >= 1
				&& ((int *)(*b)->data)[6] >= max))
			psc += ps_move(a, b, "pb\n", TRUE);
	}
	return (psc);
}

static int	st_rot(t_link **a, t_link **b, int max)
{
	int	psc;

	psc = 0;
	if (ft_link_size((*b)) < 2)
		psc += ps_move(a, b, "ra\n", TRUE);
	else if (ft_link_size((*b)) > 1)
	{
		if (((int *)(*b)->data)[6] % 2 == 0
			|| (((int *)(*b)->data)[6] % 2 >= 1
				&& ((int *)(*b)->data)[6] >= max))
			psc += ps_move(a, b, "ra\n", TRUE);
		else if (((int *)(*b)->data)[6] % 2 >= 1
			&& ((int *)(*b)->data)[6] < max)
			psc += ps_move(a, b, "rr\n", TRUE);
	}
	return (psc);
}

static int	st_cnd(t_link **a, size_t size, int chunk)
{
	if (((int *)(*a)->data)[6] <= chunk
		&& ((int *)(*a)->data)[1] != (int)(size - 1)
		&& ((int *)(*a)->data)[1] != (int)(size - 2)
		&& ((int *)(*a)->data)[1] != (int)(size - 3))
		return (1);
	else if (((int *)(*a)->data)[6] > chunk
		|| ((int *)(*a)->data)[1] == (int)(size - 1)
		|| ((int *)(*a)->data)[1] == (int)(size - 2)
		|| ((int *)(*a)->data)[1] == (int)(size - 3))
		return (2);
	return (FALSE);
}

int	ps_algo(t_link **a, t_link **b, size_t size)
{
	int		psc;
	int		max;
	int		chunk;

	psc = 0;
	chunk = 0;
	max = st_max_chunk((*a));
	if (size > 3)
	{
		while (ft_link_size((*a)) > 3)
		{
			chunk = st_chunk((*a), ft_link_size((*a)));
			if (st_cnd(a, size, chunk) == 1)
				psc += st_psh(a, b, (max - 1));
			else if (st_cnd(a, size, chunk) == 2)
				psc += st_rot(a, b, (max - 1));
		}
	}
	psc += ps_three(a, TRUE);
	psc += ps_sort(a, b, size);
	return (psc);
}
