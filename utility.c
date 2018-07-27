/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:13:49 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/25 10:28:00 by bmkhize          ###   ########.fr       */
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
	c = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2;
	if (!(str = (char *)malloc(sizeof(char) * c)))
		return (NULL);
	if (s1 && s2)
	{
		str[i] = '\0';
		ft_strlcat(str, s1, c);
		ft_strlcat(str, "|", c);
		ft_strlcat(str, s2, c);
	}
	free((void *)s1);
	return (str);
}

int		checknmake(t_array *newl, int fd)
{
	newl->line = NULL;
	newl->joinline = NULL;
	newl->c = -1;
	newl->i = 0;
	while (get_next_line(fd , &newl->line) > 0)
	{
		if(!newl->joinline)
			newl->joinline = ft_strdup("");
		if (newl->c == -1)
			newl->c = ft_wordcount(newl->line, ' ');
		else if (newl->c != (long)ft_wordcount(newl->line, ' '))
		{
			ft_strdel(&newl->joinline);
			return (-2);
		}
		newl->joinline = ft_malstrjoin(newl->joinline, newl->line);
		ft_strdel(&newl->line);
		newl->i++;
	}
	newl->arrays = ft_strsplit(newl->joinline, '|');
	ft_strdel(&newl->joinline);
	return (1);
}

size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			n++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (n);
}
