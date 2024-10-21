/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:39:05 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/13 12:45:54 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Get current time of day in milliseconds
/// @param  void Takes no param
/// @return The current time of day in milliseconds
long	p_time(void)
{
	struct timeval	tm;

	tm.tv_sec = 0;
	tm.tv_usec = 0;
	if (gettimeofday(&tm, NULL) == -1)
		return (p_err(P_ERR_FUNC_GTOFD, -1));
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

/// @brief Prints a message on STDOUT while locking the mutex
/// @param phl The current philosopher
/// @param str The string to print
/// @note This is to avoid intertwined messages
void	p_msg(t_phls *phl, char *str)
{
	long	tm;

	tm = p_time();
	pthread_mutex_lock(&phl->d->msg_lock);
	if (p_stop(phl))
		return ((void)pthread_mutex_unlock(&phl->d->msg_lock));
	printf("%ld %d %s\n", tm - phl->st_sim, phl->id + 1, str);
	pthread_mutex_unlock(&phl->d->msg_lock);
}

/// @brief Sleeps the thread for 1 millisecond in a while loop
/// @param phl The pointer to the philosopher
/// @param m_sec The amount of millisecond to sleep in total
void	p_uslp(t_phls *phl, long m_sec)
{
	long	tm_end;

	tm_end = p_time() + m_sec;
	while (p_time() < tm_end)
	{
		if (p_stop(phl))
			break ;
		usleep(1);
	}
}

/// @brief Synchronize the start of each thread
/// @param start The real time to start the simulation
/// @note This gives a space to thread creation and error checking
void	p_sync(long start)
{
	while (p_time() < start)
		usleep(1);
}

/// @brief Initialize all data for philosophers and forks
/// @param d The main data structure
/// @param i The index (always -1)
/// @return A non-zero value in case of error
int	p_init(t_prog *d, int i)
{
	if (!d)
		return (p_err(P_ERR_NULL_POINTER, 1));
	i = -1;
	d->end_flag = 0;
	d->bgn_time = p_time() + (d->arg[0] * P_START_DELAY);
	while (++i < d->arg[0])
	{
		d->phls[i].d = d;
		d->phls[i].id = i;
		d->phls[i].tt_eat = 0;
		d->phls[i].st_sim = d->bgn_time;
		d->phls[i].lt_eat = d->bgn_time;
		d->phls[i].fork_id[0] = i;
		d->phls[i].fork_id[1] = (i + 1) % d->arg[0];
		if (i % 2)
		{
			d->phls[i].fork_id[1] = i;
			d->phls[i].fork_id[0] = (i + 1) % d->arg[0];
		}
	}
	return (0);
}
