/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:24:31 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:29 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	fdf_inbase(int c, char *b, int bs)
{
	int		i;

	i = -1;
	if (bs == 10)
	{
		while (b[++i])
			if (b[i] == c)
				return (i);
	}
	else if (bs == 16)
	{
		while (b[++i])
			if (b[i] == c || b[i] + 32 == c)
				return (i);
	}
	return (-1);
}

int	fdf_atoi(char *s, int *i, char *b, int bs)
{
	int	sgn;
	int	val;

	val = 0;
	sgn = 1;
	while (s[*i] == 9 || (s[*i] > 10 && s[*i] < 14) || s[*i] == 32)
		(*i)++;
	if (s[*i] == 45)
		sgn = -1;
	if (s[*i] == 43 || s[*i] == 45)
		(*i)++;
	while (fdf_inbase(s[*i], b, bs) >= 0)
	{
		val = (val * bs) + fdf_inbase(s[*i], b, bs);
		(*i)++;
	}
	return (val * sgn);
}

static int	fdf_index(char *str, int *i, int *xval, int *yval)
{
	static int	c;

	if ((*xval) > c)
		c = (*xval);
	if (str && str[*i])
	{
		while (str[*i] == 32 || (str[*i] > 8 && str[*i] < 14))
		{
			if (str[*i] == 10)
			{
				(*xval) = 0;
				if (str[(*i) + 1] != 10)
					(*yval)++;
			}
			else if ((*i) > 0 && str[*i] == 32 && ft_isxdigit(str[(*i) - 1]))
				(*xval)++;
			(*i)++;
		}
	}
	return (c);
}

static t_point	*fdf_map(t_fdf *d, char *str)
{
	int		i;
	t_point	*cnt;
	t_point	*map;

	i = 0;
	map = NULL;
	while (str[i])
	{
		fdf_index(str, &i, &(d->mx), &(d->my));
		if (str[i])
		{
			cnt = fdf_new_point(str, &i, d->mx, d->my);
			if (!cnt)
				return (fdf_clr_point(&map), NULL);
			fdf_add_point(&map, cnt);
		}
	}
	d->mx = fdf_index(str, &i, &(d->mx), &(d->my)) + 1;
	return ((map));
}

t_point	*fdf_parse(t_fdf *d, int fd)
{
	char	*s;
	t_point	*m;

	m = NULL;
	s = fdf_read(fd);
	if (fdf_close(fd) < 0)
		return (ft_free(1, s), NULL);
	if (!s)
		return (NULL);
	m = fdf_map(d, s);
	ft_free(1, s);
	if (!m)
		ft_putendl_fd(F_ER F_ERMP, 2);
	else
	{
		fdf_link(d, m);
		ft_putendl_fd(F_SC F_SCMP, 1);
	}
	return (m);
}
