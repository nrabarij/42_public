/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:59:32 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:31:54 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ps_min(t_link **p)
{
	if (!p || !(*p))
		return (FALSE);
	if (ft_link_size((*p)) == 1)
		return (1);
	if (ft_min(ft_min(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == *((int *)(*p)->data))
		return (1);
	else if (ft_min(ft_min(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == *((int *)(*p)->next->data))
		return (2);
	else if (ft_min(ft_min(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == *((int *)(*p)->prev->data))
		return (3);
	return (FALSE);
}

static int	ps_max(t_link **p)
{
	if (!p || !(*p))
		return (FALSE);
	if (ft_link_size((*p)) == 1)
		return (1);
	if (ft_max(ft_max(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == ((int *)(*p)->data)[0])
		return (1);
	else if (ft_max(ft_max(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == ((int *)(*p)->next->data)[0])
		return (2);
	else if (ft_max(ft_max(*(int *)(*p)->data, *(int *)(*p)->prev->data),
		*(int *)(*p)->next->data) == ((int *)(*p)->prev->data)[0])
		return (3);
	return (FALSE);
}

static int	ps_set(t_link **p)
{
	if (!p || !(*p))
		return (FALSE);
	if (ft_link_size((*p)) < 3)
		return (FALSE);
	else if (ps_min(p) == 1 && ps_max(p) == 3)
		return (12);
	else if (ps_min(p) == 1 && ps_max(p) == 2)
		return (21);
	else if (ps_min(p) == 2 && ps_max(p) == 3)
		return (102);
	else if (ps_min(p) == 3 && ps_max(p) == 2)
		return (120);
	else if (ps_min(p) == 2 && ps_max(p) == 1)
		return (201);
	else if (ps_min(p) == 3 && ps_max(p) == 1)
		return (210);
	else
		return (FALSE);
	return (FALSE);
}

int	ps_three(t_link **a, int prt)
{
	if (ps_set(a) == 12)
		return (0);
	else if (ps_set(a) == 21)
		return (ps_move(a, NULL, "sa\n", prt) + ps_move(a, NULL, "ra\n", prt));
	else if (ps_set(a) == 102)
		return (ps_move(a, NULL, "sa\n", prt));
	else if (ps_set(a) == 120)
		return (ps_move(a, NULL, "rra\n", prt));
	else if (ps_set(a) == 201)
		return (ps_move(a, NULL, "ra\n", prt));
	else if (ps_set(a) == 210)
		return (ps_move(a, NULL, "sa\n", prt) + ps_move(a, NULL, "rra\n", prt));
	return (0);
}
