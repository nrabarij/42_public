/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:32:04 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/22 14:34:55 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static size_t	st_set_chunk(size_t size)
{
	if (!size)
		return (0);
	else if (size <= 35)
		return (2);
	else if (size > 35 && size <= 100)
		return (3);
	else if (size > 100 && size <= 300)
		return (4);
	else if (size > 300 && size <= 500)
		return (6);
	else if (size > 500)
		return (8);
	return (0);
}

static void	st_chunk_util(size_t **i, size_t size, size_t chunk)
{
	if (!i || !(*i) || !size || !chunk)
		return ;
	if (!((*i)[0] % 2))
		(*i)[3] = (size - (*i)[2]) / chunk;
	if ((*i)[1] > (*i)[2])
	{
		if (!(*i)[3])
			(*i)[2] += (size / chunk);
		else if ((*i)[3])
			(*i)[2] += (*i)[3];
		((*i)[0])++;
	}
}

static size_t	*st_set_util(size_t size, size_t chunk)
{
	size_t	*i;

	if (!size || !chunk)
		return (NULL);
	i = malloc(4 * sizeof(i));
	if (i)
	{
		i[0] = 1;
		i[1] = 0;
		i[2] = size / chunk;
		i[3] = 0;
		return (i);
	}
	return (NULL);
}

int	ps_chunk(t_link *a, size_t size)
{
	size_t	*i;
	size_t	chunk;

	if (!a)
		return (0);
	chunk = st_set_chunk(size);
	i = st_set_util(size, chunk);
	if (!i)
		return (0);
	while (i[1] < size)
	{
		chunk = st_set_chunk(size - i[3]);
		if (((int *)a->data)[1] <= (int)i[2]
			&& ((int *)a->data)[6] == 0)
		{
			((int *)a->data)[6] = i[0];
			(i[1])++;
		}
		st_chunk_util(&i, size, chunk);
		a = a->next;
	}
	free(i);
	return (1);
}
