/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:17 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/27 15:45:58 by bmkhize          ###   ########.fr       */
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

//void	drawDDA()
void	drawDDA(double scale, double x1, double y1, double x2, double y2, t_cal *plot, t_mlx *mlx)
{
	float x, y, dx, dy, step;
 	int i;

	(void)plot;
	(void)scale;
	dx = (x2 - x1);
	dy = (y2 - y1);
	printf("x1 = %f\t\tx2 = %f\t\ty1 = %f\t\ty2 = %f\n", x1, x2, y1, y2);
	if(fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = y1;
	i = 1;
	while(i <= step) 
	{
		mlx_pixel_put(mlx->init, mlx->win, (x - y) + 400, (x + y) / 2 + 200, 0xFF0000);
		x += dx;
		y += dy;
		i++;
	}
}

int		calc(t_cal *plot, t_array *newl, t_mlx *mlx)
{
	double x1;
	double y1;
	double x2;
	double y2;
	double scale;

	scale = 15;
	plot->ia = 0;
	plot->vx = 0;
	while (newl->arrays[plot->ia])
	{
		plot->values[0] = ft_strsplit(newl->arrays[plot->ia], ' ');
		x1 = 0;
		x2 = scale;
		while (plot->values[0][plot->vx] && plot->values[0][plot->vx + 1])
		{
			y1 = (double)ft_atoi(plot->values[0][plot->vx]) + scale * plot->ia;
			y2 = (double)ft_atoi(plot->values[0][plot->vx + 1]) + scale * plot->ia;
			drawDDA(scale, x1, y1, x2, y2, plot, mlx);
			x1 = x2;
			x2 += scale;
			plot->vx++;
		}
		if((plot->values[1] = ft_strsplit(newl->arrays[plot->ia + 1], ' ')))
		{
			x1 = 0;
			x2 = scale;
			plot->vx = 0;
			while (plot->values[0][plot->vx] && plot->values[1][plot->vx])
			{
				y1 = (double)ft_atoi(plot->values[0][plot->vx]) + scale * plot->ia;
				y2 = (double)ft_atoi(plot->values[1][plot->vx]) + scale * (plot->ia + 1);
				drawDDA(scale, x1, y1, x1, y2, plot, mlx);
				x1 = x2;
				x2 += scale;
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
	printf("arrays = %ld", sizeof(newl->arrays) * 1);
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
