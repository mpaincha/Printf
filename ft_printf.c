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
	t_elem			*tmp;

	va_start(ap, format);
	lst_arg = ft_lstdblnew();
	recover_arg(ap, lst_arg);
	tmp = lst_arg->head;
	display(format, lst_arg, tmp);
	if (lst_arg->head)
		ft_putlst(lst_arg);
	va_end(ap);
	return (1);
}
