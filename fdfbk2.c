/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:17 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/25 15:56:26 by bmkhize          ###   ########.fr       */
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

void	draw(double scale, double x1, double y1, double x2, double y2, t_cal *plot, t_mlx *mlx)//, int vert)
{
	if (y1 == y2)
	{
		while(x1 <= x2)
		{
			mlx_pixel_put(mlx->init, mlx->win, (x1 - y1) + 400, (x1 + y1) / 2 + 200, 0xFFFF);
			mlx_pixel_put(mlx->init, mlx->win, x1 + 200, y1 + 200, 0xFF0000);
			x1++;
		}
	}
	if (x1 == x2)
	{
		while(y1 <= (10 * scale) + y2)
		{
			mlx_pixel_put(mlx->init, mlx->win, (x1 - y1) + 400, (x1 + y1) / 2 + 200, 0xFFFF);
			mlx_pixel_put(mlx->init, mlx->win, x1 + 200, y1 + 200, 0xFF0000);
			y1++;
		}
	}
	else if (y1 < y2)
	{
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx->init, mlx->win, (x1 - y1) + 400, (x1 + y1) / 2 + 200, 0xFFFF);
			mlx_pixel_put(mlx->init, mlx->win, x1 + 200, y1 + 200, 0xFF0000);
			plot->mc += plot->m;
			if (plot->mc >= 0.5)
			{
				plot->mc = -0.5;
				y1++;
				printf("yeh\n");
			}
			x1++;
			plot->ix++;
		}
	}
	else if (y2 < y1)
	{
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx->init, mlx->win, (x1 - y1) + 400, (x1 + y1) / 2 + 200, 0xFFFF);
			mlx_pixel_put(mlx->init, mlx->win, x1 + 200, y1 + 200, 0xFF0000);
			plot->mc += plot->m;
			if (plot->mc <= -0.5)
			{
				plot->mc = 0.5;
				y1--;
				printf("yey\n");
			}
			x1++;
			plot->ix++;
		}
	}
}

int		calc(t_cal *plot, t_array *newl, t_mlx *mlx)
{
	double x1;
	double y1;
	double x2;
	double y2;
	double scale;

	scale = 4;
	plot->ia = 0;
	plot->vx = 0;
	while (newl->arrays[plot->ia])// && newl->arrays[plot->ia + 1])
	{
		plot->values[0] = ft_strsplit(newl->arrays[plot->ia], ' ');
		x1 = 0;
		x2 = 10 * scale;
		while (plot->values[0][plot->vx] && plot->values[0][plot->vx + 1])
		{
			y1 = (double)ft_atoi(plot->values[0][plot->vx]) + ((10 * scale) * plot->ia);
			y2 = (double)ft_atoi(plot->values[0][plot->vx + 1]) + ((10 *scale) * plot->ia);
			plot->m = (y1 - y2)/(x1 - x2);
			plot->mc = plot->m;
			draw(scale, x1, y1, x2, y2, plot, mlx);//, 0);
			x1 = x2;
			x2 += (10 * scale);
			plot->vx++;
		}
		if((plot->values[1] = ft_strsplit(newl->arrays[plot->ia + 1], ' ')))
		{
			x1 = 0;
			plot->vx = 0;
			while (plot->values[0][plot->vx] && plot->values[1][plot->vx])
			{
				y1 = (double)ft_atoi(plot->values[0][plot->vx]) + ((10 * scale) * plot->ia);
				y2 = (double)ft_atoi(plot->values[1][plot->vx]) + ((10 * scale) * plot->ia);
				plot->m = (y1 - y2)/(x1 - x2);
				plot->mc = plot->m;
				draw(scale, x1, y1, x1, y2, plot, mlx);//, 1);
				x1 += (10 * scale);
				plot->vx++;
			}
			ft_strdel(plot->values[1]);
		}
		plot->vx = 0;
		plot->ia++;
		ft_strdel(plot->values[0]);
	}
	return (0);
}

int		plot(t_mlx *mlxl, t_array *newl)
{
	t_cal plot;

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
