/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/19 17:33:58 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (nptr[i] == 32
		|| (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			s = -s;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
		res = (res * 10) + (nptr[i++] - 48);
	return (res * s);
}
