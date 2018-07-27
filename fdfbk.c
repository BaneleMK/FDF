/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:17 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/25 11:08:07 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	exit_fun(int key)
{
	if (key == 12 || key == 53)
		exit(0);
	printf("fun  =  %d\n", key);
	return (0);
}

void	mlx_init_fun(t_mlx *mlxl)
{
	mlxl->init = mlx_init();
	mlxl->win = mlx_new_window(mlxl->init, 800, 800, "FDF");
}

int		get_data(int fd, char **line)
{
	int i;

	i = get_next_line(fd, line);
	return (i);
}

int		calc(t_cal *plot, t_array *newl, t_mlx *mlx)
{	
	double x1;
	double x2;
	double y1;
	double y2;
	double yy;

	plot->i = 0;
	plot->iv = 0;
	yy = 0;
	while (newl->arrays[plot->i] && newl->arrays[plot->i + 1])
	{
		plot->values[0] = ft_strsplit(newl->arrays[plot->i], ' ');
		plot->values[1] = ft_strsplit(newl->arrays[plot->i + 1], ' ');
		x1 = 0;// not so sure how to get x - x != 0...oh well
		x2 = 50;
//		plot->b = yi1 - (m * x1) ;
		while (plot->values[0][plot->iv] && plot->values[1][plot->iv + 1])
		{
			plot->ix = 0;
			y1 = atoi(plot->values[0][plot->iv]) + yy;
			y2 = atoi(plot->values[0][plot->iv + 1]) + yy;
			plot->m = (y1 - y2)/(x1 - x2);
			plot->mc = plot->m;
			x1 = x2;// not so sure how to get x - x != 0...oh well
			x2 += 10; 
			while(plot->ix <= (x2 - x1))
			{
				mlx_pixel_put(mlx->init, mlx->win, x1 + 200, y1 + 200, 0xFFFF);
				plot->mc += plot->m;
				if (plot->mc >= 0.5)
				{
					plot->mc = -0.5;
					y1++;
				}
				x1++;
				plot->ix++;
				printf("yey\n");
			}
//			while (plot->iv);
			plot->iv++;
		}
		printf("plot->i = %d iv = %d\n", plot->i, plot->iv);
		plot->iv = 0;
	   	yy += 50;
		plot->i++;
//		free(&plot->values[0]);
//		free(&plot->values[1]);
	}
	return (0);
}

int		plot(t_mlx *mlxl, t_array *newl)
{
	t_cal plot;

	plot.i = 0;
	plot.ix = 0;
	if(!(plot.values = (char ***)malloc(sizeof(char *) * 3)))
		return (0);
	plot.values[2] = NULL;
//	(void)newl;
//	(void)mlxl;
	calc(&plot, newl, mlxl);
	return (1) ;
}

int		fdf(int fd)
{
	t_array newl;
	t_mlx 	mlxl;
	int 	n;

	if ((n = checknmake(&newl, fd)) != 1)
		return (n);
	mlx_init_fun(&mlxl);
	plot(&mlxl, &newl);
	mlx_key_hook(mlxl.win, exit_fun, 0);
	mlx_loop(mlxl.init);
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
