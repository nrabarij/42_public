/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_src.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:07:54 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:24:52 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	st_max_chunk(t_link *p)
{
	int		chunk;
	size_t	size;

	chunk = 0;
	size = ft_link_size(p);
	while (size--)
	{
		if (((int *)p->data)[6] > chunk)
			chunk = ((int *)p->data)[6];
		p = p->next;
	}
	return (chunk);
}

t_link	*ps_src(t_link *src)
{
	int		chunk;
	size_t	size;
	t_link	*cheap;

	if (!src)
		return (NULL);
	chunk = st_max_chunk(src);
	cheap = src;
	size = ft_link_size(src);
	while (size--)
	{
		if (((int *)cheap->data)[6] != chunk && ((int *)src->data)[6] == chunk)
			cheap = src;
		else if (((int *)cheap->data)[6] == chunk
			&& ((int *)src->data)[6] == chunk)
		{
			if (((int *)src->data)[5] <= ((int *)cheap->data)[5]
				&& ((int *)src->data)[1] > ((int *)cheap->data)[1])
				cheap = src;
		}
		src = src->next;
	}
	return (cheap);
}

t_link	*ps_dst(t_link *dst, t_link *cheap)
{
	if (!cheap)
		return (NULL);
	while (((int *)dst->data)[1] != ((int *)cheap->data)[3])
		dst = dst->next;
	return (dst);
}
