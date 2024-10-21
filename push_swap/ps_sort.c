/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:43:32 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:33:23 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	st_set_cnp(t_link **a, t_link **b)
{
	int	i[3];

	i[0] = 0;
	i[1] = (int)ft_link_size((*a));
	i[2] = -1;
	while (++(i[2]) < i[1])
	{
		((int *)(*a)->data)[2] = i[0];
		((int *)(*a)->data)[4] = (i[0])++;
		if (i[2] > (i[1] / 2))
			((int *)(*a)->data)[4] -= i[1];
		(*a) = (*a)->next;
	}
	i[0] = 0;
	i[1] = (int)ft_link_size((*b));
	i[2] = -1;
	while (++(i[2]) < i[1])
	{
		((int *)(*b)->data)[2] = i[0];
		((int *)(*b)->data)[4] = (i[0])++;
		if (i[2] > (i[1] / 2))
			((int *)(*b)->data)[4] -= i[1];
		(*b) = (*b)->next;
	}
}

int	ps_sort(t_link **a, t_link **b, size_t size)
{
	int		psc;
	t_link	*src;
	t_link	*dst;

	psc = 0;
	while (ft_link_size((*b)) > 0)
	{
		st_set_cnp(a, b);
		ps_tgt(a, b, size);
		src = ps_src((*b));
		dst = ps_dst((*a), src);
		psc += ps_rotate(a, b, src, dst);
		psc += ps_move(a, b, "pa\n", TRUE);
		st_set_cnp(a, b);
		ps_tgt(a, b, size);
	}
	return (psc);
}
