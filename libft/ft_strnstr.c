/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:20:16 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/17 11:44:28 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hystk, const char *ndl, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	while (hystk[i] && len > 0 && i <= len)
	{
		n = 0;
		while (hystk[i + n] == ndl[n] && (n + i) < len)
		{
			if (ndl[n + 1] == '\0')
				return ((char *)hystk + i);
			n++;
		}
		i++;
	}
	if (ndl[0] == '\0')
		return ((char *)hystk);
	return (NULL);
}
