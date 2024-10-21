/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:57:33 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/13 12:44:44 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/// @brief Execute the eating action
/// @param p The philosopher
static void	p_act_eat(t_phls *p)
{
	pthread_mutex_lock(&p->d->frks[p->fork_id[0]]);
	p_msg(p, "has taken a fork");
	pthread_mutex_lock(&p->d->frks[p->fork_id[1]]);
	p_msg(p, "has taken a fork");
	p_msg(p, "is eating");
	pthread_mutex_lock(&p->e_lock);
	p->lt_eat = p_time();
	p->tt_eat += 1;
	pthread_mutex_unlock(&p->e_lock);
	p_uslp(p, p->d->arg[2]);
	pthread_mutex_unlock(&p->d->frks[p->fork_id[0]]);
	pthread_mutex_unlock(&p->d->frks[p->fork_id[1]]);
}

/// @brief Execute the sleeping action
/// @param p The philosopher
static void	p_act_slp(t_phls *p)
{
	p_msg(p, "is sleeping");
	p_uslp(p, p->d->arg[3]);
}

/// @brief Execute the thinking action
/// @param p The philosopher
/// @param mute The indicator if the message should be printed or not
/// @note At the start of the simulation
/// every even philo will think for a certain amount of time
/// to avoid needlessly locking a fork without printing the message \note
/// Also the time to think is manually calculated for added precision
static void	p_act_thk(t_phls *p, int mute)
{
	long	tm_thk;

	tm_thk = 0;
	if (p->d->arg[2] > p->d->arg[1])
		tm_thk = p->d->arg[1];
	else
	{
		pthread_mutex_lock(&p->e_lock);
		tm_thk = (p->d->arg[1] - (p_time() - p->lt_eat) - p->d->arg[2]) / 2;
		pthread_mutex_unlock(&p->e_lock);
		if (tm_thk < 0)
			tm_thk = 0;
		else if (tm_thk > p->d->arg[2])
			tm_thk = p->d->arg[2];
	}
	if (!mute)
		p_msg(p, "is thinking");
	p_uslp(p, tm_thk);
}

/// @brief Execute the action for when there is only one philosopher
/// @param p The philosopher
/// @return Always return NULL
static void	*p_one(t_phls *p)
{
	pthread_mutex_lock(&p->d->frks[p->fork_id[0]]);
	p_msg(p, "has taken a fork");
	p_uslp(p, p->d->arg[1]);
	p_msg(p, "died");
	pthread_mutex_lock(&p->d->stp_lock);
	p->d->end_flag = 1;
	pthread_mutex_unlock(&p->d->stp_lock);
	pthread_mutex_unlock(&p->d->frks[p->fork_id[0]]);
	return (NULL);
}

/// @brief Execute the eat / sleep / think action in a while loop
/// @param ptr The philosopher
/// @return Always return NULL
void	*p_act(void *ptr)
{
	t_phls	*phl;

	phl = (t_phls *)ptr;
	p_sync(phl->st_sim);
	if (phl->d->arg[0] == 1)
		return (p_one(phl));
	if (phl->id % 2)
		p_act_thk(phl, 1);
	while (!p_stop(phl))
	{
		p_act_eat(phl);
		p_act_slp(phl);
		p_act_thk(phl, 0);
	}
	return (NULL);
}
