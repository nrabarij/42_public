/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:53:17 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:29:00 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	*ps_crt(void *av)
{
	int	*data;

	if (!av)
		return (NULL);
	data = (int *)malloc(sizeof(int) * 7);
	if (data)
	{
		data[0] = ft_atol((const char *)av);
		data[1] = 0;
		data[2] = 0;
		data[3] = 0;
		data[4] = 0;
		data[5] = 0;
		data[6] = 0;
		return ((void *)data);
	}
	return (NULL);
}

static void	ps_del(void *data)
{
	if (!data)
		return ;
	((int *)data)[0] = 0;
	((int *)data)[1] = 0;
	((int *)data)[2] = 0;
	((int *)data)[3] = 0;
	((int *)data)[4] = 0;
	((int *)data)[5] = 0;
	((int *)data)[6] = 0;
	free(data);
	data = NULL;
}

static void	*ps_exit(t_link **a, void (*del)(void *))
{
	if ((a) && (*a))
		ft_link_clear(a, del, ft_link_size((*a)));
	return (NULL);
}

static t_link	*ps_crt_pil(char **input,
					void *(*crt)(void *), void (*del)(void *))
{
	int		id;
	t_link	*new;
	t_link	*nxt;
	void	*cnt;

	if (!input || !crt || !del)
		return (NULL);
	new = NULL;
	nxt = NULL;
	id = -1;
	while (input[++id])
	{
		cnt = crt(input[id]);
		if (!cnt)
			return (ps_exit(&new, del));
		nxt = ft_link_new(cnt);
		if (!nxt)
			return (free(cnt), ps_exit(&new, del));
		ft_link_add_back(&new, nxt);
	}
	return (new);
}

int	push_swap(char **in)
{
	int		psc;
	t_link	*a;
	t_link	*b;
	size_t	sz;

	psc = 0;
	a = NULL;
	b = NULL;
	if (!in || !(*in))
		return (0);
	a = ps_crt_pil(in, &ps_crt, &ps_del);
	if (!a)
		return (-1);
	sz = ft_link_size(a);
	if (sz < 2)
		return (ft_link_clear(&a, &ps_del, sz), 0);
	if (!ps_iter(a, sz))
		return (ft_link_clear(&a, &ps_del, sz), -1);
	psc = ps_solve(&a, &b, sz);
	ft_link_clear(&a, &ps_del, ft_link_size(a));
	ft_link_clear(&b, &ps_del, ft_link_size(b));
	return (psc);
}
