/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:46:15 by bmkhize           #+#    #+#             */
/*   Updated: 2018/06/13 11:42:02 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numcal(long *z, int c, int *sign)
{
	long	i;

	*sign = 1;
	i = 1;
	if (*z < 0 && *z != 0)
	{
		*sign = -1;
		*z *= -1;
		c++;
	}
	while (*z / i != 0)
	{
		i *= 10;
		c++;
	}
	if (*z == 0)
		c = 1;
	return (c);
}

char			*ft_itoa(int n)
{
	long	i;
	int		c;
	char	*str;
	long	z;
	int		sign;

	z = n;
	c = 0;
	c = ft_numcal(&z, c, &sign);
	if (!(str = (char *)malloc(sizeof(*str) * c + 1)))
		return (NULL);
	i = 10;
	str[c] = '\0';
	while (c-- > 0)
	{
		str[c] = ((z % i) - (z % (i / 10))) / (i / 10) + '0';
		i *= 10;
		if (sign == -1 && c == 0)
			str[c] = '-';
	}
	return (str);
}
