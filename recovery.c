/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:01:37 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 11:01:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i)
{
	t_arg		sarg;

	ini_sarg(&sarg);
	if (checks(format, i, &sarg) == -1)
		return (-1);
	ft_putstr("\ni DBt SPLIT number");
	ft_putnbr(*i);
	ft_putstr("\n");
	*i = *i + 1;
	ft_putstr("\ni APRES number");
	ft_putnbr(*i);
	ft_putstr("\n");
	if (ft_strlen(sarg.spec) != 1)
		return (error("Missing specifier"));
	ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
	ini_sarg(&sarg);
	if (format[*i] != '\0')
		recover_arg(format, lst_arg, lst_str);
	return (1);
}

void	recover_param(va_list ap, t_dbllist *lst_arg)
{
	void		*arg;
	t_elem		*tmpa;

	tmpa = lst_arg->head;
	arg = (void *)1;
	while (tmpa != NULL)
	{
		arg = va_arg(ap, void *);
		ft_putstr("arg : ");
		ft_putstr((char *)arg);
		ft_putstr("\n");
		ARG->arg = arg;
		tmpa = tmpa->next;
	}
}

int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str, int *i)
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
		display_percent((percent / 2), lst_str);
		if (percent % 2 == 0)
		{
			*i = *i + 1;
			return (0);
		}
	}
	*i = *i + 1;
	if (split_arg(format, lst_arg, lst_str, i) == -1)
	{
		clean_lst(lst_arg);
		return (-1);
	}
	return (1);
}

void	recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str)
{
	static	int	i = 0;

	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i) == -1)
			return ;
		else if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i) == 0)
			continue;
		else if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i) == 1)
			continue ;
		else if (i < (int)ft_strlen(format) && ft_isascii(format[i]))
			i = stock_str(format, i, lst_str);
		i++;
	}
}
