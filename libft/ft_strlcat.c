/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:33:45 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/24 17:38:57 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	st_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	size_t		dl;
	size_t		tl;

	s = src;
	dl = 0;
	while (dst[dl] && dl < size)
		dl++;
	if (dl < size)
		tl = dl + st_strlen(src);
	else
		return (size + st_strlen(src));
	while (*s && (dl + 1) < size)
	{
		dst[dl] = *s++;
		dl++;
	}
	dst[dl] = '\0';
	return (tl);
}
