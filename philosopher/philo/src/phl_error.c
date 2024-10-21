/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:02:02 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/13 13:42:40 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Print an error message on STDERR
/// @param str The string to print, if non-NULL
/// @param ret The return value
/// @return The given value in parameter
/// @note Used for (int) or (long) type functions
long	p_err(const char *str, long ret)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(2, str, i);
	}
	return (ret);
}

/// @brief Converts a given string to its integer counterpart
/// @param s The string to convert if any
/// @return The integer value [0 to 2147483647]
static long	st_atoi(const char *s)
{
	long	i;
	long	res;

	if (!s)
		return (p_err(P_ERR_NULL_POINTER, -1));
	i = -1;
	res = 0;
	while (s[++i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
		else
			res = (res * 10) + (s[i] - 48);
	}
	if (res > INT_MAX)
		return (-1);
	return (res);
}

/// @brief Prints an error message on STDERR if any error is encountered
/// @param j The index to check for error
/// @param d The data structure
/// @return A non-zero value on error
static int	st_chk_arg(int j, t_prog *d)
{
	if (j == 0 && (d->arg[j] < 1 || d->arg[j] > P_MAX_NB))
		return (p_err(P_ERR_INVAL_NB_PHL, 1));
	else if (j == 1 && d->arg[j] < 0)
		return (p_err(P_ERR_INVAL_TM_DIE, 1));
	else if (j == 2 && d->arg[j] < 0)
		return (p_err(P_ERR_INVAL_TM_EAT, 1));
	else if (j == 3 && d->arg[j] < 0)
		return (p_err(P_ERR_INVAL_TM_SLP, 1));
	else if (j == 4 && d->arg[j] < 0)
		return (p_err(P_ERR_INVAL_NB_EAT, 1));
	return (0);
}

/// @brief Checks the values of argv and Assigns them to the data structure
/// @param ac The number of argument (from main [ac - 1])
/// @param av The pointer to the first element (from main [av[1]])
/// @param d The data structure
/// @return 1 on error, 0 or 2 otherwise
int	p_args(int ac, char **av, t_prog *d)
{
	int	i;
	int	j;

	if (!av)
		return (1);
	i = -1;
	d->arg[4] = -1;
	while (++i < ac)
		d->arg[i] = st_atoi(av[i]);
	i = 0;
	j = -1;
	while (++j < ac)
		i += st_chk_arg(j, d);
	if (i == 0 && av[4] && d->arg[4] == 0 && d->arg[1] > 0)
		return (2);
	else if (i > 0)
		return (1);
	return (0);
}
