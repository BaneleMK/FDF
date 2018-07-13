/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:17:17 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/14 16:16:25 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long i;

	i = ft_strlen(s);
	if (c != '\0')
		i--;
	while (s[i] != (char)c && i != -1)
	{
		if ((char)c != '\0' && s[i] == '\0')
			break ;
		i--;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
