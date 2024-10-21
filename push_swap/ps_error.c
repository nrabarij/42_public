/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:24:49 by nrabarij          #+#    #+#             */
/*   Updated: 2024/04/21 13:51:15 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	not_dgt(const char *s)
{
	int	i;

	i = 0;
	if ((s[i] == 43 || s[i] == 45) && s[i + 1])
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] && !ft_isdigit(s[i]))
		return (TRUE);
	return (FALSE);
}

static int	dup_zero(const char *s1, const char *s2, int i, int j)
{
	if (s1[0] == 43)
		i++;
	if (s2[0] == 43)
		j++;
	if (s1[0] == 45 && s2[0] == 45)
	{
		i++;
		j++;
	}
	while (s1[i] == 48)
		i++;
	while (s2[j] == 48)
		j++;
	while (s1[i] && s2[j] && (s1[i] == s2[j]))
	{
		i++;
		j++;
	}
	if (!s1[i] && !s2[j])
		return (TRUE);
	return (FALSE);
}

static int	is_dup(const char *s1, const char *s2, int i, int j)
{
	if ((s1[i] == 43 || s1[i] == 45) && (s1[i + 1] == 48))
		i++;
	if ((s2[j] == 43 || s2[j] == 45) && (s2[j + 1] == 48))
		j++;
	while (s1[i] == 48)
		i++;
	while (s2[j] == 48)
		j++;
	if (!s1[i] && !s2[j])
		return (TRUE);
	else if (s1[i] && s2[j])
		return (dup_zero(s1, s2, 0, 0));
	return (FALSE);
}

int	ps_error(char **in)
{
	int	i;
	int	j;

	if (!in || !(*in))
		return (FALSE);
	i = -1;
	while (in[++i])
	{
		if (ft_atol(in[i]) < INT_MIN
			|| ft_atol(in[i]) > INT_MAX)
			return (TRUE);
		if (not_dgt(in[i]) || in[i][0] == 0)
			return (TRUE);
		j = i;
		while (in[++j])
			if (is_dup(in[i], in[j], 0, 0))
				return (TRUE);
	}
	return (FALSE);
}
