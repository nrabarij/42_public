/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/21 16:12:15 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	st_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	else
		st_bzero(p, nmemb * size);
	return (p);
}
