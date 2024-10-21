/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/21 18:08:03 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_length(int nb)
{
	int	len;

	len = 0;
	if (nb < 1)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static long long	st_abs(long long n)
{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

static char	*st_malloc(size_t n)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_itoa(int n)
{
	int				s;
	unsigned int	nb;
	int				len;
	char			*res;

	s = 0;
	if (n < 0)
		s = 1;
	len = st_length(n);
	res = st_malloc(len);
	if (!res)
		return (NULL);
	res[len] = '\0';
	nb = st_abs(n);
	while (len--)
	{
		res[len] = (nb % 10) + 48;
		nb /= 10;
	}
	if (s)
		res[0] = 45;
	return (res);
}
