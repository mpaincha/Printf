/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 12:09:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/21 12:09:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_sarg(t_arg *sarg)
{
	sarg->arg = NULL;
	sarg->flags = ft_strnew(sizeof(char) * 5);
	sarg->numb = 0;
	sarg->length = ft_strnew(sizeof(char) * 2);
	sarg->prec = ft_strnew(sizeof(char) * 1);
	sarg->spec = ft_strnew(sizeof(char) * 1);
	sarg->type = NULL;
}

int		split_arg(const char *format, t_dbllist *lst_arg, int *i,
				t_elem *tmp)
{
	while (format[*i] != '\0')
	{
		if (check_flags(format[*i], tmp))
		{
			*i = *i + 1;
			if (check_number(ft_strsub(format, *i, ft_strlen(format) - *i),
				tmp, i))
				*i = *i + 1;
		}
		else if (check_length(format[*i], tmp))
			*i = *i + 1;
		else if (check_prec(format[*i], format[*i + 1], i, tmp))
			*i = *i + 1;
		else if (check_spec(format[*i], tmp))
			break ;
		else
			return (error("Parameter problem"));
	}
	*i = *i + 1;
	if (ft_strlen(ARG->spec) != 1)
		return (error("Missing specifier"));
	tmp = tmp->next;
	if (format[*i] != '\0')
		display(format, lst_arg, tmp);
	return (1);
}

void	recover_arg(va_list ap, t_dbllist *lst_arg)
{
	t_arg	sarg;
	void	*arg;

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
