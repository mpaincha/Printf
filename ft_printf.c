/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:12:51 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:12:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_dbllist		*lst_arg;
	t_dbllist		*lst_str;
	t_elem			*tmpa;

	va_start(ap, format);
	lst_arg = ft_lstdblnew();
	lst_str = ft_lstdblnew();
	recover_param(ap, lst_arg);
	tmpa = lst_arg->head;
	recover_arg(format, lst_arg, lst_str, tmpa);
	if (lst_arg->head) //debug
		ft_putlst(lst_arg); //debug
	if (lst_str->head) //debug
		ft_putlststr(lst_str); //debug
	cleanarg(lst_arg);
	if (lst_arg->head) //debug
		ft_putlst(lst_arg); //debug
	action(lst_arg, lst_str);
	va_end(ap);
	return (1);
}
