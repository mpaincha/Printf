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

void	display_percent(int nb)
{
	while (nb > 0)
	{
		ft_putchar('%');
		nb--;
	}
}

int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i, t_elem *tmp)
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
		display_percent(percent / 2);
		if (percent % 2 == 0)
		{
			*i = *i + 1;
			return (0);
		}
	}
	*i = *i + 1;
	if (split_arg(format, lst_arg, lst_str, i, tmp) == -1)
	{
		clean_lst(lst_arg);
		return (-1);
	}
	return (1);
}

int		stock_str(const char *format, int	i)
{
	char 	*str;
	int		start;

	str = NULL;
	start = i;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	str = ft_strsub(format, start, (i - start));
	ft_putstr("str :");
	ft_putstr(str);
	ft_putstr("\n");
	return (i - 1);
}

void	display(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, t_elem *tmp)
{
	static	int	i = 0;

	while (i < (int)ft_strlen(format))
	{
		ft_putstr("\nvaleur de i :");
		ft_putnbr(i);
		ft_putstr("\n");
		if (format[i] == '%' && percent(format, lst_arg, lst_str, &i, tmp) == -1)
			return ;
		else if (format[i] == '%' && percent(format, lst_arg, lst_str, &i, tmp) == 0)
			continue;
		else if (format[i] == '%' && percent(format, lst_arg, lst_str, &i, tmp) == 1)
			continue ;
		else if (i < (int)ft_strlen(format) && ft_isascii(format[i]))
		{
			i = stock_str(format, i);
			ft_putstr("\nvaleur de i :");
			ft_putnbr(i);
			ft_putstr("\n");
		}
		i++;
		ft_putstr("\nfin boucle\n");
	}
}
