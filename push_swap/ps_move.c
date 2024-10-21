/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:02:53 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:31:00 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ps_cmp(char *in)
{
	if (!ft_strncmp("sa\n", in, 3))
		return (10);
	else if (!ft_strncmp("sb\n", in, 3))
		return (11);
	else if (!ft_strncmp("ss\n", in, 3))
		return (12);
	else if (!ft_strncmp("pa\n", in, 3))
		return (20);
	else if (!ft_strncmp("pb\n", in, 3))
		return (21);
	else if (!ft_strncmp("ra\n", in, 3))
		return (30);
	else if (!ft_strncmp("rb\n", in, 3))
		return (31);
	else if (!ft_strncmp("rr\n", in, 3))
		return (32);
	else if (!ft_strncmp("rra\n", in, 4))
		return (40);
	else if (!ft_strncmp("rrb\n", in, 4))
		return (41);
	else if (!ft_strncmp("rrr\n", in, 4))
		return (42);
	return (-1);
}

static int	ps_swp(t_link **a, t_link **b, int code)
{
	if (code == 10 && ft_link_size((*a)) > 1)
		return (ps_pilswp_top(a, NULL), 1);
	else if (code == 11 && ft_link_size((*b)) > 1)
		return (ps_pilswp_top(NULL, b), 1);
	else if (code == 12 && ft_link_size((*a)) > 1 && ft_link_size((*b)) > 1)
		return (ps_pilswp_top(a, b), 1);
	return (0);
}

static int	ps_psh(t_link **a, t_link **b, int code)
{
	if (code == 20 && (b) && (*b))
		return (ps_pshelm_top_to_top(b, a), 1);
	else if (code == 21 && (a) && (*a))
		return (ps_pshelm_top_to_top(a, b), 1);
	return (0);
}

static int	ps_rot(t_link **a, t_link **b, int code)
{
	if (code == 30 && ft_link_size((*a)) > 0)
		return (ps_rotate_pil(a, NULL), 1);
	else if (code == 31 && ft_link_size((*b)) > 0)
		return (ps_rotate_pil(NULL, b), 1);
	else if (code == 32 && ft_link_size((*a)) > 0 && ft_link_size((*b)) > 0)
		return (ps_rotate_pil(a, b), 1);
	else if (code == 40 && ft_link_size((*a)) > 0)
		return (ps_revrot_pil(a, NULL), 1);
	else if (code == 41 && ft_link_size((*b)) > 0)
		return (ps_revrot_pil(NULL, b), 1);
	else if (code == 42 && ft_link_size((*a)) > 0 && ft_link_size((*b)) > 0)
		return (ps_revrot_pil(a, b), 1);
	return (0);
}

int	ps_move(t_link **a, t_link **b, char *in, int prt)
{
	int	psc;
	int	code;

	psc = 0;
	if (!in)
		return (0);
	code = ps_cmp(in);
	if (code == -1)
		return (-1);
	else if (code == 10 || code == 11 || code == 12)
		psc += ps_swp(a, b, code);
	else if (code == 20 || code == 21)
		psc += ps_psh(a, b, code);
	else if (code == 30 || code == 31 || code == 32
		|| code == 40 || code == 41 || code == 42)
		psc += ps_rot(a, b, code);
	if (prt)
		ft_putstr_fd(in, 1);
	return (psc);
}
