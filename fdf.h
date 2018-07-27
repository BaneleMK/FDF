/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:17:31 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/26 14:13:20 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H__
# define FDF_H__

# include "libft/libft.h"
# include <mlx.h>
//# include "MLX/ft_libgfx/minilibx_X11_sources/mlx.h"
# include <fcntl.h>
# include <math.h>

#include <stdio.h>

typedef struct		s_array
{
	char			**arrays;
	char			*joinline;
	char			*line;
	long			c; // iterater for join
	long			i; // iterater for join
	size_t			*wlen;
}					t_array;

typedef struct		s_mlx
{
	int				i;
	void			*init;
	void			*win;
}					t_mlx;

/*
** y = mx + b
*/

typedef struct		s_cal
{
	char			***values;
	int				ia;
	int				vx;
	int				ix;
	double			m;
	double			mc;
	int				b;
	int				slope;
	int				x;
	int				y;
}					t_cal;

char				*ft_malstrjoin(char const *s1, char const *s2);
int					checknmake(t_array *newl, int fd);
size_t				ft_wordcount(const char *s, char c);

#endif
