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
	t_mlx 	mlxl;
	
	int 	n;
	if ((n = checknmake(&newl, fd)) != 1)
		return (n);
	mlxl.i = 0;
	while (newl.arrays[mlxl.i])
	{
		ft_putendl(newl.arrays[mlxl.i]);
		mlxl.i++;
	}
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
				ft_putstr("[FAIL]\n");
			else if (ret == -2)
				ft_putstr("Found wrong line length. Exiting.\n");
		}
		else
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
		}
		close(fd);
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	return (0);
}
