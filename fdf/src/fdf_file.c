/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:46 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:19:42 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	fdf_open(char *file)
{
	int	fd;

	if (!file || !(*file))
		return (ft_putendl_fd(F_ER F_NONAME, 2), -1);
	if (ft_strrncmp(file, ".fdf", 4))
		return (ft_putendl_fd(F_ER F_FORMAT, 2), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(F_ER);
	else
		ft_putendl_fd(F_SC F_SCOP, 1);
	return (fd);
}

int	fdf_close(int fd)
{
	int	c;

	c = close(fd);
	if (c < 0)
		perror(F_ER);
	else
		ft_putendl_fd(F_SC F_SCCL, 1);
	return (c);
}

static char	*fdf_join(char *str, char *tmp)
{
	char	*cat;

	cat = NULL;
	if (tmp)
	{
		if (!str)
			return (ft_strdup(tmp));
		else if (str)
		{
			cat = ft_strjoin(str, tmp);
			ft_free(1, str);
			return (cat);
		}
		return (NULL);
	}
	return (NULL);
}

char	*fdf_read(int fd)
{
	int		i[2];
	char	*tmp[2];

	i[0] = 1;
	i[1] = 1;
	tmp[0] = NULL;
	while (i[0])
	{
		tmp[1] = ft_calloc((F_BUFF * i[1]) + 1, sizeof(char));
		if (!tmp[1])
			return (ft_free(2, tmp[0], tmp[1]), perror(F_ER), NULL);
		i[0] = read(fd, tmp[1], (F_BUFF * i[1]));
		if (i[0] < 0)
			return (ft_free(2, tmp[0], tmp[1]), perror(F_ER), NULL);
		tmp[0] = fdf_join(tmp[0], tmp[1]);
		if (!(tmp[0]))
			return (perror(F_ER), ft_free(1, tmp[1]), NULL);
		if (tmp[0] && !i[0])
			return (ft_putendl_fd(F_SC F_SCRD, 1), ft_free(1, tmp[1]), tmp[0]);
		ft_free(1, tmp[1]);
		i[1] += i[1];
	}
	return (perror(F_ER), NULL);
}

void	fdf_use(void)
{
	ft_putendl_fd(F_USE ": ./fdf \"file_name.fdf\"\n"
		"The FDF program takes a file as its parameter:\n"
		"- The file must be in .fdf format.\n"
		"- The file must be available for read.\n"
		"- The file must have at least one coordinate.\n"
		"If a required condition is not met, "
		"the program will abort its operation.", 2);
	exit(1);
}
