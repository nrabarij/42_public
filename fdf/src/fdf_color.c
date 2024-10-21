/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:07 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:47 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	fdf_grad(int pos, int step, int st, int en)
{
	int		cnew[3];
	double	cinc[3];

	if (st == en)
		return (st);
	cinc[0] = (double)((((en >> 16) & 0xFF) - ((st >> 16) & 0xFF))) / step;
	cinc[1] = (double)((((en >> 8) & 0xFF) - ((st >> 8) & 0xFF))) / step;
	cinc[2] = (double)((((en) & 0xFF) - ((st) & 0xFF))) / step;
	cnew[0] = round((double)(cinc[0] * pos)) + ((st >> 16) & 0xFF);
	cnew[1] = round((double)(cinc[1] * pos)) + ((st >> 8) & 0xFF);
	cnew[2] = round((double)(cinc[2] * pos)) + ((st) & 0xFF);
	return (((cnew[0] << 16) + (cnew[1] << 8) + (cnew[2])));
}
