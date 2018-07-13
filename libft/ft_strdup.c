/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:17:52 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/16 21:40:04 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup_str;

	i = 0;
	if (!(dup_str = (char *)malloc(sizeof(*s1) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dup_str[i] = s1[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
