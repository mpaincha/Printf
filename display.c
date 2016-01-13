/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:22:01 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 18:22:02 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	display_percent(int	nb)
{
	while (nb > 0)
	{
		ft_putchar('%');
		nb--;
	}
}


void	display(const char *format)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			percent(format, &i);
		else if (ft_isascii(format[i]))
			ft_putchar(format[i]);
		i++;
	}
}
