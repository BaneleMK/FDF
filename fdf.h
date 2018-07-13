/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:17:31 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/12 16:44:00 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H__
# define FDF_H__

# include "libft/libft.h"
//# include <mlx.h>
# include "MLX/ft_libgfx/minilibx_X11_sources/mlx.h"
# include <fcntl.h>

typedef struct		s_array
{
	char			*joinline;
	char			**arrays;
	long			c; // iterater for join
	long			i; // iterater for join
	size_t			n; // number of lines
}					t_array;

typedef struct		s_mlx
{
	int				i;
}					t_mlx;

char				*ft_malstrjoin(char const *s1, char const *s2);
int					checknmake(t_array *newl, int fd);

#endif
