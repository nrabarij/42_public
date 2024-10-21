/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:58:50 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/11 15:16:58 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Sub-function in p_mutex()
static int	st_mtx_init(t_prog *d, int i)
{
	while (++i < d->arg[0])
	{
		if (pthread_mutex_init(&d->frks[i], NULL))
			return (p_err(P_ERR_THRD_MUTEX_INIT, 1));
		if (pthread_mutex_init(&d->phls[i].e_lock, NULL))
			return (p_err(P_ERR_THRD_MUTEX_INIT, 1));
	}
	if (pthread_mutex_init(&d->msg_lock, NULL))
		return (p_err(P_ERR_THRD_MUTEX_INIT, 1));
	if (pthread_mutex_init(&d->stp_lock, NULL))
		return (p_err(P_ERR_THRD_MUTEX_INIT, 1));
	return (0);
}

/// @brief Sub-function in p_mutex()
static int	st_mtx_dest(t_prog *d, int i)
{
	while (++i < d->arg[0])
	{
		if (pthread_mutex_destroy(&d->frks[i]))
			return (p_err(P_ERR_THRD_MUTEX_DESTROY, 1));
		if (pthread_mutex_destroy(&d->phls[i].e_lock))
			return (p_err(P_ERR_THRD_MUTEX_DESTROY, 1));
	}
	if (pthread_mutex_destroy(&d->msg_lock))
		return (p_err(P_ERR_THRD_MUTEX_DESTROY, 1));
	if (pthread_mutex_destroy(&d->stp_lock))
		return (p_err(P_ERR_THRD_MUTEX_DESTROY, 1));
	return (0);
}

/// @brief Initializes or Destroys all mutexes for data structure
/// @param d The data structure
/// @param cod 0 for initialization and 1 for destruction
/// @param i The starting index (always -1)
/// @return A non-zero value on error
int	p_mutex(t_prog *d, int cod, int i)
{
	if (!d)
		return (p_err(P_ERR_NULL_POINTER, 1));
	i = -1;
	if (cod == 0)
	{
		if (st_mtx_init(d, i))
			return (1);
	}
	else if (cod == 1)
	{
		if (st_mtx_dest(d, i))
			return (1);
	}
	return (0);
}
