/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:20:18 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/14 16:34:55 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t s1_len;
	size_t i;

	s1_len = ft_strlen(dst);
	i = ft_strlen(src);
	if (s1_len < dstsize)
		ft_strncat(dst, src, dstsize - s1_len - 1);
	else if (s1_len >= dstsize || dstsize == 0)
		return (dstsize + i);
	return (s1_len + i);
}
