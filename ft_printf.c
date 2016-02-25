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
// 		ft_putstr("\nspec  : ");
// 		// ft_putstr("Point :");
// 		ft_putstr(ARG->spec);
// 		ft_putstr("\nSMOD.l  : ");
// 		ft_putnbr(SMOD.l);
// 		// ft_putstr("\nNum :");
// 		// ft_putnbr(SPREC.n);
// 		ft_putstr("\n");
// 		tmpa = tmpa->next;
// 	}
// }

void			ft_putlstt(t_dbllist *list)
{
	t_elem	*tmps;

	tmps = list->head;
		ft_putstr("\n====LIST str =====\n");

	while (tmps != NULL)
	{
		ft_putstr("str : ");
		// ft_putstr("Point :");
		ft_putstr(SSTR->str);
		ft_putstr("\nNum :");
		ft_putnbr(SSTR->n);
		// ft_putnbr(SPREC.n);
		ft_putstr("\n");
		tmps = tmps->next;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_dbllist		*lst_arg;
	t_dbllist		*lst_str;
	int				i;
	int				oct;
	int				cpt_null;

	i = 0;
	oct = 0;
	cpt_null = 0;
	va_start(ap, format);
	lst_arg = ft_lstdblnew();
	lst_str = ft_lstdblnew();
	if (recover_arg(format, lst_arg, lst_str, &i) == -1)
		return(0);
	// ft_putstr("recover arg ok");
	if (lst_arg == NULL)
		return (0);
	recover_param(ap, lst_arg);
	cleanarg(lst_arg);
	// ft_putlstarg(lst_arg); //
	// ft_putlststr(lst_str, &oct); //
	transformation(lst_arg, lst_str, &cpt_null);
	// ft_putstr("ok transfo");//
	if (lst_str->head)
		ft_putlststr(lst_str, &oct);
	if (cpt_null != 0)
		oct = oct + cpt_null;
	// ft_lstdbldel(&lst_arg);
	// free(lst_arg);
	// ft_lstdbldel(&lst_str);
	// free(lst_str);
	va_end(ap);
	return (oct);
}
