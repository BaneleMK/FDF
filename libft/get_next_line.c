/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:59:14 by bmkhize           #+#    #+#             */
/*   Updated: 2018/07/09 12:02:39 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_malstrjoin(char const *s1, char const *s2)
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

static void		readnstore(int fd, t_some *newl)
{
	newl->newline = NULL;
	newl->lines = NULL;
	newl->strnew = 0;
	newl->i = 0;
	newl->ret = 0;
	newl->prv_fd = fd;
	ft_bzero(newl->buff, BUFF_SIZE);
	while ((newl->ret = read(fd, newl->buff, BUFF_SIZE)) > 0)
	{
		newl->buff[newl->ret] = '\0';
		if (newl->strnew == 0)
		{
			newl->newline = ft_strnew(newl->ret);
			ft_memcpy(newl->newline, newl->buff, newl->ret);
			newl->strnew = 1;
		}
		else
			newl->newline = ft_malstrjoin(newl->newline, newl->buff);
	}
	if (newl->ret != -1 && newl->strnew == 1)
		newl->ret = 1;
}

static size_t	ft_linestart(const char *s, char c, t_some *newl)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i])
		{
			if (n == newl->i)
				break ;
			while (s[i] != c && s[i])
				i++;
			n++;
		}
		if (s[i] == c && s[i])
			i++;
	}
	return (i);
}

static int		retline(t_some *newl, char **line)
{
	size_t i;

	i = 0;
	newl->st = ft_linestart(newl->newline, '\n', newl);
	if (newl->newline[newl->st])
	{
		while (newl->newline[newl->st + i] != '\n'
				&& newl->newline[newl->st + i] != '\0')
			i++;
		*line = ft_strsub(newl->newline, newl->st, i);
		return (1);
	}
	ft_strdel(&newl->newline);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_some	newl;

	if (fd == -1 || line == NULL)
		return (-1);
	if (newl.fdini != 1)
	{
		newl.fdini = 1;
		newl.prv_fd = -1;
	}
	if (newl.prv_fd != fd || newl.strnew == 0)
		readnstore(fd, &newl);
	if (newl.ret == -1)
		return (-1);
	if (newl.ret != 1 && newl.strnew == 0)
		return (0);
	if (retline(&newl, line) > 0)
	{
		newl.i++;
		return (1);
	}
	newl.strnew = 0;
	return (0);
}
