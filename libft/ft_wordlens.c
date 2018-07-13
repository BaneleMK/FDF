/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:09:23 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/17 12:10:39 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlens(const char *s, char c, size_t x)
{
	size_t	i;
	size_t	n;
	size_t	l;

	i = 0;
	n = 0;
	l = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i + l] != c && s[i + l] && n == x)
				l++;
			while (s[i] != c && s[i] && n != x)
				i++;
			n++;
		}
	}
	return (l);
}
