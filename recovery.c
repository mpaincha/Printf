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

char	*convert_char(t_elem *tmpa, void *arg)
{
	if (ARG->spec[0] == 'c')
	{
		if (SMOD.l == 0)
			return (ft_itoabase_imax((int)arg, 10));
		// A VOIR apres c avec l qui correspond 0 C
	}
	if (ARG->spec[0] == 'u' || ARG->spec[0] == 'U' || ARG->spec[0] == 'd'
		|| ARG->spec[0] == 'D' ||ARG->spec[0] == 'i')
		return (ft_itoabase_imax(arg, 10));
	if (ARG->spec[0] == 'o' || ARG->spec[0] == 'O' )
		return (ft_itoabase_imax(arg, 8));
	if (ARG->spec[0] == 's' || ARG->spec[0] == 'S')
		return ((char *)arg);
	if (ARG->spec[0] == 'p' || ARG->spec[0] == 'X')
		return (ft_itoabase_imax(arg, 16));
	if (ARG->spec[0] == 'x')
		return (ft_itoabase_imax_x(arg, 16));
	return (0);
}

int		split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i)
{
	t_arg		sarg;

	ini_sarg(&sarg);
	if (checks(format, i, &sarg) == -1)
		return (-1);
	*i = *i + 1;
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
	void		*recup;
	t_elem		*tmpa;
	char		*arg;

	tmpa = lst_arg->head;
	recup = (void *)1;
	while (tmpa != NULL)
	{
		recup = va_arg(ap, void *);
		arg = ft_strdup(convert_char(tmpa, recup));
		ARG->arg = arg;
		tmpa = tmpa->next;
	}
}

int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i)
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

int		recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str)
{
	static	int	i = 0;
	int		ret;

	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			ret = percent(format, lst_arg, lst_str, &i);
			if (ret == -1)
				return (-1);
		}
		else if (i < (int)ft_strlen(format) && ft_isascii(format[i]))
			i = stock_str(format, i, lst_str);
		i++;
	}
	return (1);
}
