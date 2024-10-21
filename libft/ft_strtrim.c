/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/20 15:21:06 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	st_inset(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*d1;

	i = 0;
	j = st_strlen(s1);
	while (s1[i] && st_inset(s1[i], set))
		i++;
	while (j > i && st_inset(s1[j - 1], set))
		j--;
	d1 = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!d1)
		return (NULL);
	k = 0;
	while (s1[i] && i < j)
		d1[k++] = s1[i++];
	d1[k] = '\0';
	return (d1);
}
