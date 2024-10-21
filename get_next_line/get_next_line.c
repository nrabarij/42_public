/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:02:59 by nrabarij          #+#    #+#             */
/*   Updated: 2024/03/14 17:28:47 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// To concatenate two strings in case the BUFFER_SIZE is small enough
// and no '\n' was found yet.
char	*gnl_cat(char *next, char *tmp)
{
	char	*cat;

	cat = ft_strjoin(next, tmp);
	return (free(next), cat);
}

// There are two possible situations:
// - first, if BUFFER_SIZE is big enough, there might be more than one line
// 		fetched in one signle read
// - second, if BUFFER_SIZE is small enough, there might be no '\n' fetched
// In order to address both situations, we use strjoin while no '\n' is found
// Then, if a '\n' is already found, break the loop.
// On the first call to gnl_read, *next is uninitialized, that's why we
// allocate memory with calloc.
// Initialize rd (the number of bytes read) to 1, in order to enter the loop.
// If there is an error on reading the file, return NULL.
// If a call to read is successful, add '\0' at the end of the string fetched.
// This will avoid any error in a call to gnl_cat().
char	*gnl_read(char *next, int fd)
{
	int		rd;
	char	*tmp;

	if (!next)
		next = ft_calloc(1, sizeof(char));
	if (!next)
		return (NULL);
	rd = 1;
	while (rd && !ft_strchr(next, 10))
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp)
			return (free(next), NULL);
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 0)
			return (free(next), free(tmp), NULL);
		next = gnl_cat(next, tmp);
		if (!next)
			return (free(tmp), next);
		free(tmp);
	}
	if (next[0] == 0)
		return (free(next), NULL);
	return (next);
}

// After gnl_read() call, there may be more than one '\n' found.
// In that case, fetch only the line up to the first '\n'.
// Allocate enough memory to line:
// - up to the first '\n' encountered
// - then +1 for the '\n' itself, if there is at least one
// - and again +1 for the '\0' to comply with a standard C-String
char	*gnl_line(char *next)
{
	int		i;
	char	*line;

	i = 0;
	if (!next)
		return (NULL);
	while (next[i] && next[i] != 10)
		i++;
	if (next[i] == 0)
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (next[i] && next[i] != 10)
	{
		line[i] = next[i];
		i++;
	}
	if (next[i] == 10)
		line[i] = 10;
	return (line);
}

// After the first call to get_next_line() there is already a value
// in the static char *next. Since it is static, the value will stay
// valid until the program ends.
// In order to return the next line, we must delete the previous line
// that was already returned during the first call.
char	*gnl_next(char *next, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!next)
		return (NULL);
	if (!next[i] || !line)
		return (free(next), NULL);
	while (next[i] && next[i] != 10)
		i++;
	if (!next[i])
		return (free(next), NULL);
	tmp = ft_calloc(ft_strlen(next) - i + 1, sizeof(char));
	if (!tmp)
		return (free(next), NULL);
	i++;
	j = 0;
	while (next[i])
		tmp[j++] = next[i++];
	if (*tmp == 0)
		return (free(tmp), free(next), NULL);
	return (free(next), tmp);
}

// Error handling comes first:
// - if the fd is not valid (negative fd)
// - if we cannot read the file; read returns a positive int on success
//		including zero (0)
// - if the BUFFER_SIZE is zero or is negative
// Afterwards, fetch the buffer according to buffer size -> gnl_read()
// If there is an error in gnl_read() return NULL.
// Then, fetch line -> gnl_line
// And finally, fetch next -> gnl_next
char	*get_next_line(int fd)
{
	char		*line;
	static char	*next[FDS];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next[fd] = gnl_read(next[fd], fd);
	if (!next[fd])
		return (NULL);
	line = gnl_line(next[fd]);
	next[fd] = gnl_next(next[fd], line);
	return (line);
}
