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

int		percent(const char *format, int *i)
{
	int		percent;

	percent = 1;
	while (format[*i + 1] == '%')
	{
		percent++;
		*i = *i + 1;
	}
	if (percent > 1)
	{
		display_percent(percent/2);
		if (percent % 2 == 0)
			return (0);
	}
	if (!recovery_arg(format, i))
		return (0);
	return (1);
}

void	display(const char *format)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(format))
	{
		printf("boucle DISPLAY===\n");
		if (format[i] == '%')
			percent(format, &i);
		else if (ft_isascii(format[i]))
			ft_putchar(format[i]);
		i++;
	}
}
