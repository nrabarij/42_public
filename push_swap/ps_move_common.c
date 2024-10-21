/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_common.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:02:53 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:41:40 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_rotate_pil(t_link **a, t_link **b)
{
	if (a && (*a))
		(*a) = (*a)->next;
	if (b && (*b))
		(*b) = (*b)->next;
}

void	ps_revrot_pil(t_link **a, t_link **b)
{
	if (a && (*a))
		(*a) = (*a)->prev;
	if (b && (*b))
		(*b) = (*b)->prev;
}

void	ps_pilswp_top(t_link **a, t_link **b)
{
	void	*tmp;

	if (a && (*a) && ft_link_size((*a)) > 1)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
	}
	if (b && (*b) && ft_link_size((*b)) > 1)
	{
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
	}
}

t_link	*ps_remelm_top(t_link **p)
{
	t_link	*tmp;

	tmp = (*p);
	(*p) = (*p)->next;
	(*p)->prev->prev->next = (*p);
	(*p)->prev = (*p)->prev->prev;
	return (tmp);
}

void	ps_pshelm_top_to_top(t_link **src, t_link **dst)
{
	size_t	i;
	t_link	*tmp;

	if (!src || !(*src))
		return ;
	i = ft_link_size((*src));
	tmp = ps_remelm_top(src);
	ft_link_add_front(dst, tmp);
	if (i == 1)
		(*src) = NULL;
}
