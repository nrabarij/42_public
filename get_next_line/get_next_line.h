/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:02:51 by nrabarij          #+#    #+#             */
/*   Updated: 2024/03/14 16:03:19 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*	standard libc *********************************************************** */
# include <unistd.h>		//read
# include <stdlib.h>		//malloc, free
/*	definitions ************************************************************* */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FDS
#  define FDS 1024
# endif
/*	structure *************************************************************** */
/*	functions *************************************************************** */
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
