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


// static void			ft_putlstarg(t_dbllist *list)
// {
// 	t_elem	*tmpa;

// 	tmpa = list->head;
// 		ft_putstr("\n====LIST ARG =====\n");

// 	while (tmpa != NULL)
// 	{
// 		ft_putstr("PREC\n");
// 		ft_putstr("Point :");
// 		ft_putnbr(SPREC.pt);
// 		ft_putstr("\nNum :");
// 		ft_putnbr(SPREC.n);
// 		ft_putstr("\n");
// 		tmpa = tmpa->next;
// 	}
// }

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_dbllist		*lst_arg;
	t_dbllist		*lst_str;
	int				i;
	int				oct;

	i = 0;
	oct = 0;
	va_start(ap, format);
	lst_arg = ft_lstdblnew();
	lst_str = ft_lstdblnew();
	if (recover_arg(format, lst_arg, lst_str, &i) == -1)
		return(0);
	if (lst_arg == NULL)
		return (0);
	recover_param(ap, lst_arg);
	// if (lst_arg->head)
	// 	ft_putlstarg(lst_arg);
	cleanarg(lst_arg);
	transformation(lst_arg, lst_str);
	if (lst_str->head)
		ft_putlststr(lst_str, &oct);
	// ft_lstdbldel(&lst_arg);
	// free(lst_arg);
	// ft_lstdbldel(&lst_str);
	// free(lst_str);
	va_end(ap);
	return (oct);
}
