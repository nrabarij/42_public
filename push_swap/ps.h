/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:16:57 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/30 10:42:17 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <limits.h>
# include "libft/libft.h"

char	**ps_input(char **av);
int		ps_error(char **in);
int		push_swap(char **in);
int		ps_three(t_link **a, int prt);
int		ps_iter(t_link *a, size_t size);
int		ps_chunk(t_link *a, size_t size);
int		ps_algo(t_link **a, t_link **b, size_t size);
int		ps_solve(t_link **a, t_link **b, size_t size);
int		ps_move(t_link **a, t_link **b, char *in, int prt);
int		ps_sort(t_link **a, t_link **b, size_t size);
int		ps_rotate(t_link **a, t_link **b, t_link *src, t_link *dst);
void	ps_tgt(t_link **dst, t_link **src, size_t sz);
t_link	*ps_src(t_link *src);
t_link	*ps_dst(t_link *dst, t_link *cheap);

int		st_max_chunk(t_link *p);

void	ps_rotate_pil(t_link **a, t_link **b);
void	ps_revrot_pil(t_link **a, t_link **b);
void	ps_pilswp_top(t_link **a, t_link **b);
t_link	*ps_remelm_top(t_link **p);
void	ps_pshelm_top_to_top(t_link **src, t_link **dst);

#endif
