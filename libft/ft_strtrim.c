/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:14:13 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/13 14:10:01 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordstartt(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			i++;
		}
		else
			return (i);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	st;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s) - 1;
	while ((s[len] == 32 || s[len] == 10 || s[len] == 9))
		len--;
	st = ft_wordstartt(s);
	if (!(str = (char *)malloc((sizeof(*s) * (len - st + 2)))))
		return (0);
	while (i < len - st + 1)
	{
		str[i] = s[st + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
