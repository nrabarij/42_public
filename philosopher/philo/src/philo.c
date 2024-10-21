/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:02:04 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/15 14:07:06 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Starts the simulation by creating the threads
/// @param d The data structure
/// @return A non-zero value in case of error
static int	p_sim_bgn(t_prog *d)
{
	int	i;

	i = -1;
	while (++i < d->arg[0])
	{
		if (pthread_create(&d->phls[i].th, NULL, p_act, &d->phls[i]))
			return (p_err(P_ERR_THRD_CREAT, 1));
	}
	if (d->arg[0] > 1)
		if (pthread_create(&d->checker, NULL, p_chk, d))
			return (p_err(P_ERR_THRD_CREAT, 1));
	return (0);
}

/// @brief Ends the simulation by joining the threads
/// @param d The data structure
/// @return A non-zero value in case of error
static int	p_sim_end(t_prog *d)
{
	int	i;

	i = -1;
	while (++i < d->arg[0])
	{
		if (pthread_join(d->phls[i].th, NULL))
			return (p_err(P_ERR_THRD_JOIN, 1));
	}
	if (d->arg[0] > 1)
		if (pthread_join(d->checker, NULL))
			return (p_err(P_ERR_THRD_JOIN, 1));
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_prog			d;
	t_phls			phl[P_MAX_NB];
	pthread_mutex_t	frk[P_MAX_NB];

	if (ac < 5 || ac > 6)
		return (p_err(P_ERR_INVAL_NB_ARG P_ERR_INVAL_PR_USE, 1));
	d.phls = phl;
	d.frks = frk;
	i = p_args(ac - 1, &av[1], &d);
	if (i)
		return (i % 2);
	if (p_init(&d, -1))
		return (1);
	if (p_mutex(&d, 0, -1))
		return (1);
	if (p_sim_bgn(&d))
		return ((void)p_mutex(&d, 1, -1), 1);
	if (p_sim_end(&d))
		return ((void)p_mutex(&d, 1, -1), 1);
	p_mutex(&d, 1, -1);
	return (0);
}
