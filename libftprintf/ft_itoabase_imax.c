/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_imax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 10:43:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/09 10:43:11 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlenbase_imax(intmax_t n, size_t base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_itoabase_imax(intmax_t n, size_t base)
{
	char			*str;
	int				i;
	size_t			len;

	len = ft_intlenbase(n, base);
	i = 0;
	str = ft_strnew(len + 1);
	if (base == 10 && n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		if (base > 10 && n % base >= 10)
			str[--len] = (n % base) + 55;
		else
			str[--len] = (n % base) + 48;
		n = n / base;
	}
	return (str);
}