/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:13:19 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/13 16:07:53 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t l1;
	size_t l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	if ((l1 >= n && l2 >= n) || l1 == l2)
	{
		if (ft_strncmp(s1, s2, n) != 0)
			return (0);
		return (1);
	}
	return (0);
}
