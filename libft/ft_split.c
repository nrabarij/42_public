/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/24 10:26:23 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
typedef struct s_split
{
	int					init;
	const char			*s;
	int					sl;
	char				c;
	int					st;
	int					en;
	int					x;
	int					y;
}						t_split;
*/
static int	st_wrdcnt(const char *s, char c)
{
	int	wc;
	int	chk;

	wc = 0;
	chk = 0;
	while (*s)
	{
		if (*s != c && chk == 0)
		{
			chk = 1;
			wc++;
		}
		else if (*s == c)
			chk = 0;
		s++;
	}
	return (wc);
}

static char	**st_init(t_split *p, const char *s, char c)
{
	if (!p)
	{
		free(p);
		return (NULL);
	}
	p->sl = 0;
	while (s[p->sl])
		p->sl++;
	p->init = p->sl;
	if (p->init != 1)
	{
		p->c = c;
		p->en = 0;
		p->x = 0;
		p->st = -1;
		p->s = s;
		p->init = 1;
	}
	return ((char **)malloc(sizeof(char *) * (st_wrdcnt(s, c) + 1)));
}

static char	**st_wrdcpy(t_split *p, char **strs)
{
	strs[p->x] = (char *)malloc(sizeof(char) * (p->en - p->st + 1));
	if (!(strs[p->x]))
	{
		while ((p->x) >= 0)
			free(strs[(p->x)--]);
		free(strs);
		strs = NULL;
		free(p);
		return (strs);
	}
	p->y = 0;
	while (p->st < p->en)
	{
		strs[p->x][p->y] = p->s[p->st];
		(p->y)++;
		(p->st)++;
	}
	strs[p->x][p->y] = '\0';
	p->st = -1;
	p->x++;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	t_split	*p;
	char	**strs;

	if (!s)
		return (NULL);
	p = (t_split *)malloc(sizeof(t_split));
	if (!p)
		return (st_init(p, s, c));
	strs = st_init(p, s, c);
	if (strs)
	{
		while (p->en <= p->sl && p->x < st_wrdcnt(s, c))
		{
			if (s[p->en] != c && p->st < 0)
				p->st = p->en;
			else if ((s[p->en] == c || p->en == p->sl) && p->st >= 0)
				strs = st_wrdcpy(p, strs);
			if (strs == NULL)
				return (NULL);
			p->en++;
		}
		strs[p->x] = NULL;
	}
	free(p);
	return (strs);
}
