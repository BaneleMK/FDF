/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:17 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/12 17:08:46 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		get_data(int fd, char **line)
{
	int i;

	i = get_next_line(fd, line);
	return (i);
}

int		fdf(int fd)
{
	t_array newl;
	char	*line;
	char	*joinline;
	long	i;

	line = NULL;
	joinline = NULL;
	newl.c = -1;
	i = 0;
	while (get_data(fd , &line) > 0)
	{
		if(!joinline)
			joinline = ft_strdup(line);
		if (newl.c == -1)
			newl.c = ft_strlen(line);
		else if (newl.c != (long)ft_strlen(line))
			return (-2);
		joinline = ft_strjoin(joinline ,line);
		ft_strdel(&line);
		i++;
	}
	if(!(newl.arrays = (char **)malloc(sizeof(char *) * i + 1)))
		return (0);
	newl.arrays[i] = NULL;
	printf("c = %ld\n", newl.c);
	while (i > 0)
	{
		newl.arrays[i] = ft_strsub(joinline, i * newl.c, newl.c);
		printf("line = %s\n", newl.arrays[i]);
		printf("i * c = %ld\n\n", i * newl.c);
		i--;
	}
/*	while (newl.arrays[i++ + 1])
	{
		ft_putendl(newl.arrays[i]);
	}*/
	return (1);
}

int		fdfx(int fd)
{
	char	*line;
	char	*joinline;
	char	*tmpline;
	long	c;

	line = NULL;
	c = -1;
	joinline = ft_strdup("");
	while (get_data(fd , &line) > 0)
	{
		if (c == -1)
			c = ft_strlen(line);
		else if (c != (long)ft_strlen(line))
			return (-2);
		tmpline = joinline;
		joinline = ft_strjoin(joinline ,line);
		ft_strdel(&tmpline);
		ft_strdel(&line);
	}
//	ft_putstr(joinline);
	return (1);
}

int 	main(int argc, char **argv)
{
	int fd;
	int ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			ret = fdf(fd);
			if (ret == 0)
				ft_putstr("[FAIL]");
			else if (ret == -2)
				ft_putstr("Found wrong line length. Exiting.");
		}
		else
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
		}
		close(fd);
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}
