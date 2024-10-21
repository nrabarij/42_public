/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:46 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:24 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_fdf	*d;

	if (ac == 2)
	{
		fd = fdf_open(av[1]);
		if (fd < 0)
			exit(1);
		d = fdf_alloc(fd);
		if (!d)
		{
			fdf_close(fd);
			exit(1);
		}
		if (fdf_init(d, fd))
			exit(1);
		fdf_free(d);
		exit(0);
	}
	fdf_use();
}
