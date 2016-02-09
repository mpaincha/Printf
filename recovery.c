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
	if (ARG->spec[0] == 's')
		return (convert_s(tmpa, arg));
	if (ARG->spec[0] == 'S')
		return (convert_su(tmpa, arg));
	if (ARG->spec[0] == 'p')
		return (convert_p(tmpa, arg));
	if (ARG->spec[0] == 'd' || ARG->spec[0] == 'i')
		return (convert_di(tmpa, arg));
	if (ARG->spec[0] == 'D')
		return (convert_du(tmpa, arg));
	if (ARG->spec[0] == 'o')
		return (convert_o(tmpa, arg));
	if (ARG->spec[0] == 'O' )
		return (convert_ou(tmpa, arg));
	if (ARG->spec[0] == 'u')
		return (convert_u(tmpa, arg));
	if (ARG->spec[0] == 'U')
		return (convert_uu(tmpa, arg));
	if (ARG->spec[0] == 'x')
		return (convert_x(tmpa, arg));
	if (ARG->spec[0] == 'X')
		return (convert_xu(tmpa, arg));
	if (ARG->spec[0] == 'c')
		return (convert_c(tmpa, arg));
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
