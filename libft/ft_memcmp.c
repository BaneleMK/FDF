/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:55:09 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/13 12:38:42 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned	char *)s2;
	i = 0;
	if (!st1 && !st2)
		return (0);
	if (n > 0)
	{
		while (i < n - 1)
		{
			if (st1[i] == st2[i])
				i++;
			else
				break ;
		}
	}
	else
		return (0);
	return (st1[i] - st2[i]);
}
