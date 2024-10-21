/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/21 18:07:07 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	while (*big && len--)
	{
		j = 0;
		while ((big[j] == little[j]) && little[j] && j <= len)
		{
			if (!little[j + 1])
				return ((char *)big);
			j++;
		}
		big++;
	}
	return (NULL);
}
