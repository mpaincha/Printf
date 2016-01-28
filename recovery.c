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

int		split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i, t_elem *tmpA)
{
	while (format[*i] != '\0')
	{
		if (check_flags(format[*i], tmpA))
		{
			*i = *i + 1;
			if (check_number(ft_strsub(format, *i, ft_strlen(format) - *i),
				tmpA->content, i))
				*i = *i + 1;
		}
		else if (check_length(format[*i], tmpA))
			*i = *i + 1;
		else if (check_prec(format[*i], format[*i + 1], i, tmpA))
			*i = *i + 1;
		else if (check_spec(format[*i], tmpA))
			break ;
		else
			return (error("Parameter problem"));
	}
	*i = *i + 1;
	if (ft_strlen(ARG->spec) != 1)
		return (error("Missing specifier"));
	tmpA = tmpA->next;
	if (format[*i] != '\0')
		recover_arg(format, lst_arg, lst_str, tmpA);
	return (1);
}

void	recover_param(va_list ap, t_dbllist *lst_arg)
{
	t_arg		sarg;
	void		*arg;

	ft_putstr("\n====recover param====\n");
	ini_sarg(&sarg);
	arg = (void *)1;
	while (1)
	{
		ini_sarg(&sarg);
		arg = va_arg(ap, void *);
		if (arg == NULL)
			break ;
		sarg.arg = arg;
		ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
	}
}

int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i, t_elem *tmpA)
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
	if (split_arg(format, lst_arg, lst_str, i, tmpA) == -1)
	{
		clean_lst(lst_arg);
		return (-1);
	}
	return (1);
}

void	recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		t_elem *tmpA)
{
	static	int	i = 0;

	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i, tmpA) == -1)
			return ;
		else if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i, tmpA) == 0)
			continue;
		else if (format[i] == '%'
		&& percent(format, lst_arg, lst_str, &i, tmpA) == 1)
			continue ;
		else if (i < (int)ft_strlen(format) && ft_isascii(format[i]))
			i = stock_str(format, i, lst_str);
		i++;
	}
}
