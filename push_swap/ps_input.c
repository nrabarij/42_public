/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:41:51 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/24 18:12:16 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static char	*st_parse(char *blk, char *av)
{
	char	*tmp;
	char	*cat;

	cat = NULL;
	if (!blk && !(*av))
		return (NULL);
	else if (!blk && (*av))
		return (ft_strdup(av));
	else if (blk && !(*av))
		return (free(blk), NULL);
	else if (blk && (*av))
	{
		tmp = ft_strjoin(blk, " ");
		if (tmp)
		{
			cat = ft_strjoin(tmp, av);
			free(tmp);
		}
		free(blk);
	}
	return (cat);
}

static int	st_chk_arg(char *blk)
{
	size_t	i;
	size_t	len;

	if (!blk)
		return (FALSE);
	i = 0;
	len = ft_strlen(blk);
	while (ft_isspace(blk[i]))
		i++;
	if (i > 0 && i == len)
		return (TRUE);
	return (FALSE);
}

static void	*st_error(char *to_free)
{
	if (to_free)
		free(to_free);
	return (NULL);
}

char	**ps_input(char **av)
{
	int		i;
	char	*blk;
	char	**in;

	i = 1;
	in = NULL;
	blk = NULL;
	if (!av || !(*av))
		return (NULL);
	while (av[i])
	{
		if (st_chk_arg(av[i]))
			return (st_error(blk));
		blk = st_parse(blk, av[i]);
		if (!blk)
			return (NULL);
		i++;
	}
	in = ft_split(blk, 32);
	free(blk);
	return (in);
}
