/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:03:56 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/28 15:32:27 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcounts(const char *s, char c)
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

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	size_t	n;
	size_t	st;

	if (!s || !c)
		return (0);
	n = 0;
	if (!(str = (char **)malloc(sizeof(*str) * (ft_wordcounts(s, c) + 1))))
		return (0);
	while (n < ft_wordcounts(s, c))
	{
		st = ft_wordstarts(s, c, n);
		str[n] = ft_strsub(s, st, ft_wordlens(s, c, n));
		n++;
	}
	str[n] = NULL;
	return (str);
}
