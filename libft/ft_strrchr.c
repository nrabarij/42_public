/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/21 17:24:36 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = st_strlen(s);
	while (i >= 0)
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
