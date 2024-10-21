/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:02:44 by nrabarij          #+#    #+#             */
/*   Updated: 2024/03/14 16:47:10 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	void			*p;
	unsigned char	*ptr;

	p = (void *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	else
	{
		i = 0;
		ptr = (unsigned char *)p;
		while (i++ < (nmemb * size))
			*(ptr++) = '\0';
	}
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	sl;
	char	*new;

	if (s1 && s2)
	{
		sl = ft_strlen(s1);
		new = (char *)malloc(sizeof(char) * (sl + ft_strlen(s2) + 1));
		if (!new)
			return (NULL);
		i = -1;
		while (s1[++i])
			new[i] = s1[i];
		i = -1;
		while (s2[++i])
			new[sl++] = s2[i];
		new[sl] = '\0';
		return (new);
	}
	return (NULL);
}
