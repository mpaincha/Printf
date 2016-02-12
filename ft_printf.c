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
	int				i;

	i = 0;
	va_start(ap, format);
	lst_arg = ft_lstdblnew();
	lst_str = ft_lstdblnew();
	recover_arg(format, lst_arg, lst_str, &i);
	if (lst_arg == NULL)
		return (0);
	recover_param(ap, lst_arg);
	// if (lst_str->head) //debug
	// 	ft_putlststr(lst_str); //debug
	// if (lst_arg->head) //debug
	// 	ft_putlst(lst_arg); //debug
	cleanarg(lst_arg);
	if (lst_arg->head) //debug
		ft_putlst(lst_arg); //debug
	transformation(lst_arg, lst_str);
	if (lst_str->head) //debug
		ft_putlststr(lst_str); //debug
	va_end(ap);
	return (1);
}
