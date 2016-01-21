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

int		percent(const char *format, t_dbllist *lst_arg, int *i)
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
			return (1);
	}
	*i = *i + 1;
	//return (split_arg(format, lst_arg, i) == 0) ? 0 : 1;
	if (split_arg(format,lst_arg, i) == -1)
	{
		clean_lst(lst_arg);
		return (-1);
	}
	return (1);

}

void	display(const char *format, t_dbllist *lst_arg)
{
	static	int	i = 0;

	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%' && percent(format, lst_arg, &i) == -1)
		{
			i = 0;
			return ;
		}
		else if (format[i] == '%' && percent(format, lst_arg, &i) == 1)
			continue;
		else if (i < (int)ft_strlen(format) && ft_isascii(format[i]))
			ft_putchar(format[i]);
		i++;
	}
}
