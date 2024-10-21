/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:01:31 by nrabarij          #+#    #+#             */
/*   Updated: 2024/07/12 23:36:43 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/// headers **************************************************************** ///

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

/// custom headers ********************************************************* ///

# include "phl_const.h"
# include "phl_struct.h"

/// function prototypes **************************************************** ///

// phl_action.c

void	*p_act(void *ptr);

// phl_check.c

void	*p_chk(void *ptr);
int		p_stop(t_phls *phl);

// phl_error.c

long	p_err(const char *str, long ret);
int		p_args(int ac, char **av, t_prog *d);

// phl_mutex.c

int		p_mutex(t_prog *d, int cod, int i);

// phl_utils.c

long	p_time(void);
void	p_sync(long start);
int		p_init(t_prog *d, int i);
void	p_uslp(t_phls *phl, long m_sec);
void	p_msg(t_phls *phl, char *str);

#endif
