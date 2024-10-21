/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:05:20 by nrabarij          #+#    #+#             */
/*   Updated: 2024/02/19 13:55:32 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (st_isupper(c))
		return (c + 32);
	return (c);
}
