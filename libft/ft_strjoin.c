/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/22 15:10:05 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	sl;
	char	*new;

	if (s1 && s2)
	{
		sl = st_strlen(s1);
		new = (char *)malloc(sizeof(char) * (sl + st_strlen(s2) + 1));
		if (!new)
			return (NULL);
		i = -1;
		while (s1[++i])
			new[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			new[sl] = s2[i];
			sl++;
		}
		new[sl] = '\0';
		return (new);
	}
	return (NULL);
}
