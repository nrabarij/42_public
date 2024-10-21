/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:14:49 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:21:41 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	*st_crt_tab(t_link *a, size_t size)
{
	size_t	i;
	int		*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * size);
	if (tab)
	{
		while (i < size)
		{
			tab[i++] = ((int *)a->data)[0];
			a = a->next;
		}
		return (tab);
	}
	return (NULL);
}

static void	st_tab(int *tab, int size)
{
	int	x;
	int	temp;

	x = 0;
	while (x < size -1)
	{
		if (tab[x] > tab[x + 1])
		{
			temp = tab[x];
			tab[x] = tab[x + 1];
			tab[x + 1] = temp;
			x = 0;
		}
		else
			x++;
	}
}

static void	st_id(t_link *a, int size, int *t, int j)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (((int *)a->data)[0] == t[j])
				((int *)a->data)[1] = j;
		a = a->next;
	}
}

int	ps_iter(t_link *a, size_t size)
{
	int		*t;

	t = NULL;
	t = st_crt_tab(a, size);
	if (!t)
		return (FALSE);
	st_tab(t, (int)size);
	st_id(a, (int)size, t, 0);
	free(t);
	if (!ps_chunk(a, size))
		return (FALSE);
	return (TRUE);
}
