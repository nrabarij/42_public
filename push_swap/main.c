/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:31:29 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/24 13:37:51 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	st_exit(char **in, int code)
{
	int		i;

	if (code)
		ft_putendl_fd("\e[0;31mError\e[0m", code + 1);
	if (in)
	{
		i = -1;
		while (in[++i])
			free(in[i]);
		free(in);
	}
	exit(code);
}

int	main(int ac, char **av)
{
	int		i;
	char	**in;

	i = 0;
	in = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	else if (ac > 1)
	{
		in = ps_input(av);
		if (!in)
			st_exit(in, EXIT_FAILURE);
		if (ps_error(in))
			st_exit(in, EXIT_FAILURE);
		i = push_swap(in);
		if (i == -1)
			st_exit(in, EXIT_FAILURE);
		else if (i >= 0)
			st_exit(in, EXIT_SUCCESS);
	}
	return (0);
}
