/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phl_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:36:50 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/12 09:44:16 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHL_CONST_H
# define PHL_CONST_H

/// constant definitions *************************************************** ///

# define P_MAX_NB 255

# define P_START_DELAY 20

# define P_ERR_INVAL_NB_PHL "\e[31mError\e[0m: invalid \
number_of_philosophers\n"

# define P_ERR_INVAL_TM_DIE "\e[31mError\e[0m: invalid \
time_to_die (milliseconds)\n"

# define P_ERR_INVAL_TM_EAT "\e[31mError\e[0m: invalid \
time_to_eat (milliseconds)\n"

# define P_ERR_INVAL_TM_SLP "\e[31mError\e[0m: invalid \
time_to_sleep (milliseconds)\n"

# define P_ERR_INVAL_NB_EAT "\e[31mError\e[0m: invalid \
number_of_times_each_philosopher_must_eat (optional)\n"

# define P_ERR_INVAL_NB_ARG "\e[31mError\e[0m: invalid \
arguments\n"

# define P_ERR_INVAL_PR_USE "\e[33mUsage\e[0m: ./philo \
<number_of_philosophers> \
<time_to_die> \
<time_to_eat> \
<time_to_sleep> \
<number_of_times_each_philosopher_must_eat (optional)>\n\
\tparam_1: [1; 255]\n\
\tparam_2: [0; 2147483647]\n\
\tparam_3: [0; 2147483647]\n\
\tparam_4: [0; 2147483647]\n\
\tparam_5: [0; 2147483647] (optional)\n"

# define P_ERR_THRD_MUTEX_INIT "\e[31mError\e[0m: cannot init mutex\n"

# define P_ERR_THRD_MUTEX_DESTROY "\e[31mError\e[0m: cannot destroy mutex\n"

# define P_ERR_THRD_CREAT "\e[31mError\e[0m: cannot create thread\n"

# define P_ERR_THRD_JOIN "\e[31mError\e[0m: cannot join thread\n"

# define P_ERR_FUNC_GTOFD "\e[31mError\e[0m: gettimeofday()\n"

# define P_ERR_NULL_POINTER "\e[31mError\e[0m: invalid argument (null)\n"

#endif
