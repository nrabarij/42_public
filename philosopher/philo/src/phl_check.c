/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 04:09:57 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/12 23:35:27 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Checks if the simulation has already stopped
/// @param phl The pointer to a philosopher
/// @return The value of the flag. 0 if simulation can continue
int	p_stop(t_phls *phl)
{
	int	i;

	pthread_mutex_lock(&phl->d->stp_lock);
	i = phl->d->end_flag;
	pthread_mutex_unlock(&phl->d->stp_lock);
	return (i);
}

/// @brief Checks if a philo has not eaten since its last eat or the start time
/// @param phl The pointer to the philosopher
/// @return A non-zero value if TRUE
static int	p_no_eat(t_phls *phl)
{
	if (p_time() - phl->lt_eat >= phl->d->arg[1])
	{
		pthread_mutex_lock(&phl->d->stp_lock);
		phl->d->end_flag = 1;
		pthread_mutex_unlock(&phl->d->stp_lock);
		pthread_mutex_lock(&phl->d->msg_lock);
		printf("%ld %d died\n", p_time() - phl->d->bgn_time, phl->id + 1);
		pthread_mutex_unlock(&phl->d->msg_lock);
		pthread_mutex_unlock(&phl->e_lock);
		return (1);
	}
	return (0);
}

/// @brief Iterates through the array of philosopher
/// @param d The data structure
/// @return A non-zero value if one or more philosopher died or if all philo ate
static int	p_end_sim(t_prog *d)
{
	int	i;
	int	done_eat;

	i = -1;
	done_eat = 1;
	while (++i < d->arg[0])
	{
		pthread_mutex_lock(&d->phls[i].e_lock);
		if (p_no_eat(&d->phls[i]))
			return (1);
		if (d->arg[4] > 0)
			if (d->phls[i].tt_eat < d->arg[4])
				done_eat = 0;
		pthread_mutex_unlock(&d->phls[i].e_lock);
	}
	if (d->arg[4] > 0 && done_eat)
	{
		pthread_mutex_lock(&d->stp_lock);
		d->end_flag = 1;
		pthread_mutex_unlock(&d->stp_lock);
		return (1);
	}
	return (0);
}

/// @brief Checks if any philo died or if all philo have eaten
/// @param ptr The pointer to the data structure
/// @return Always return NULL
/// @note The return value is not checked
void	*p_chk(void *ptr)
{
	t_prog	*d;

	d = (t_prog *)ptr;
	p_sync(d->bgn_time);
	while (1)
	{
		if (p_end_sim(d))
			return (NULL);
		usleep(1);
	}
	return (NULL);
}
