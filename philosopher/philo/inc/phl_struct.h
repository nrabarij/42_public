/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:36:50 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/13 12:46:17 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHL_STRUCT_H
# define PHL_STRUCT_H

# ifndef PHILO_H
#  include <stdio.h>
#  include <unistd.h>
#  include <limits.h>
#  include <pthread.h>
#  include <sys/time.h>
# endif

/// structure definitions ************************************************** ///

/// @brief Data structure for main program
/// @note Here is a list of all elements in this structure \note
/// --- \note
/// arg[0] -> number of philosophers \note
/// arg[1] -> time to die \note
/// arg[2] -> time to eat \note
/// arg[3] -> time to sleep \note
/// arg[4] -> number of time to eat \note
/// --- \note
/// end_flag -> flag to indicate that the simulation has stopped \note
/// bgn_time -> the exact time to start simulation \note
/// --- \note
/// msg_lock -> lock for msg \note
/// stp_lock -> lock for end \note
/// --- \note
/// phl[x] -> pointer to the array of philosophers \note
/// frk[x] -> lock for each fork \note
/// checker  -> the thread to check if a philo died / if all philo has eaten
typedef struct s_prog	t_prog;

/// @brief Data structure for each philo
/// @note Here is a list of all elements in this structure \note
/// --- \note
/// d  -> the pointer to the main data structure \note
/// id -> the philosopher id \note
/// th -> the philosopher as a thread \note
/// --- \note
/// tt_eat -> number of time the philosopher has eaten \note
/// lt_eat -> the last time the philosopher has eaten \note
/// st_sim -> the start time of the philosopher \note
/// e_lock -> lock for eating (read / write value of eating state) \note
/// --- \note
/// fork_id[0] -> the id of its associated left fork \note
/// fork_id[1] -> the id of its associated right fork
typedef struct s_phls
{
	t_prog				*d;
	int					id;
	pthread_t			th;
	long				tt_eat;
	long				lt_eat;
	long				st_sim;
	pthread_mutex_t		e_lock;
	int					fork_id[2];
}						t_phls;

typedef struct s_prog
{
	long				arg[5];
	t_phls				*phls;
	pthread_mutex_t		*frks;
	pthread_mutex_t		msg_lock;
	pthread_mutex_t		stp_lock;
	long				end_flag;
	long				bgn_time;
	pthread_t			checker;
}						t_prog;

#endif
