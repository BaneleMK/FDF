/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:13:49 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/12 16:31:05 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_malstrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	c = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(str = (char *)malloc(sizeof(char) * c)))
		return (NULL);
	if (s1 && s2)
	{
		str[i] = '\0';
		str = ft_strncat(str, s1, ft_strlen(s1));
		str = ft_strncat(str, s2, ft_strlen(s2));
	}
	free((void *)s1);
	return (str);
}

int		linetoarray(t_array *newl)
{
	if(!(newl->arrays = (char **)malloc(sizeof(char *) * newl->i + 1))) /*notice check if whether i is right*/
	{
		ft_strdel(&newl->joinline);
		return (0);
	}
	newl->arrays[newl->i] = NULL;
	while (newl->i > 0)
	{
		newl->i--;
		newl->arrays[newl->i] = 
			ft_strsub(newl->joinline, (newl->i + 1 )* newl->c, newl->c);
	}
	ft_strdel(&newl->joinline);
	return (1);
}

int		checknmake(t_array *newl, int fd)
{
	char	*line;

	line = NULL;
	newl->joinline = NULL;
	newl->c = -1;
	newl->i = 0;
	while (get_next_line(fd , &line) > 0)
	{
		if(!newl->joinline)
			newl->joinline = ft_strdup(line);
		if (newl->c == -1)
			newl->c = ft_strlen(line);
		else if (newl->c != (long)ft_strlen(line))
		{
			ft_strdel(&newl->joinline);
			return (-2);
		}
		newl->joinline = ft_strjoin(newl->joinline ,line);
		ft_strdel(&line);
		newl->i++;
	}
	return(linetoarray(newl));
}
