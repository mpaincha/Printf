/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_imax_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 10:43:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/09 10:43:11 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoabase_imax_x(intmax_t n, size_t base)
{
	char			*str;
	int				i;
	size_t			len;

	len = ft_intlenbase_imax(n, base);
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
			str[--len] = (n % base) + 87;
		else
			str[--len] = (n % base) + 48;
		n = n / base;
	}
	return (str);
}

