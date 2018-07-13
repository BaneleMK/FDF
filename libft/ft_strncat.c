/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:08:04 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/12 11:40:55 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (i < n && n > 0)
	{
		if (s2[i])
			s1[s1_len + i] = s2[i];
		else
			break ;
		i++;
	}
	s1[s1_len + i] = '\0';
	return (s1);
}
