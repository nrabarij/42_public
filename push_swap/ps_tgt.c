/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tgt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:07:54 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:33:56 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	st_tgt(t_link *p, int src, size_t sz)
{
	int		tgt;
	size_t	size;

	if (!p || (src == (int)(sz - 1)))
		return (0);
	tgt = ((int *)p->data)[1];
	size = (int)ft_link_size(p);
	while (size--)
	{
		if (((int *)p->data)[1] > tgt)
			tgt = ((int *)p->data)[1];
		p = p->next;
	}
	size = (int)ft_link_size(p);
	while (size--)
	{
		if (((int *)p->data)[1] > src && ((int *)p->data)[1] < tgt)
			tgt = ((int *)p->data)[1];
		p = p->next;
	}
	return (tgt);
}

static int	st_ttc(t_link *dst, t_link *src, int tgt)
{
	int	ttc;
	int	i[2];
	int	s[2];

	ttc = INT_MAX;
	while (((int *)dst->data)[1] != tgt)
		dst = dst->next;
	i[0] = ft_abs(((int *)dst->data)[4]);
	i[1] = ft_abs(((int *)src->data)[4]);
	s[0] = (int)(ft_link_size(dst) / 2);
	s[1] = (int)(ft_link_size(src) / 2);
	if ((((int *)dst->data)[2] <= s[0] && ((int *)src->data)[2] <= s[1])
		|| (((int *)dst->data)[2] > s[0] && ((int *)src->data)[2] > s[1]))
		ttc = (i[0] + i[1]) - ft_min(i[0], i[1]);
	else
		ttc = i[0] + i[1];
	return (ttc);
}

void	ps_tgt(t_link **dst, t_link **src, size_t sz)
{
	size_t	size;

	if (!(dst) || !(*dst) || !(src) || !(*src))
		return ;
	size = ft_link_size((*src));
	while (size--)
	{
		((int *)(*src)->data)[3] = st_tgt((*dst), ((int *)(*src)->data)[1], sz);
		((int *)(*src)->data)[5] = st_ttc((*dst), (*src),
				((int *)(*src)->data)[3]);
		(*src) = (*src)->next;
	}
}
