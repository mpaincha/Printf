/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:22:01 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 18:22:02 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_elem	*find_pos(char *spec, t_dbllist *lst_str)
{
	int			found;
	t_elem		*tmps;

	tmps = lst_str->head;
	found = 0;
	// ft_putstr("\n===FIND POS====\n"); //

	while (tmps != NULL && !found)
	{
		// ft_putstr("\nSSTR"); //
		// ft_putstr(SSTR->str); //
		// ft_putstr("\n SSTR.n"); //
		// ft_putnbr(SSTR->n); //
		// ft_putstr("\n"); //
		if (ft_strequ(SSTR->str, spec) && SSTR->n == 0)
		{
			// ft_putstr("  found\n"); //
			found = 1;
			SSTR->n = 1;
			break ;
		}
		else
			tmps = tmps->next;
	}
	if (found == 0)
		tmps = NULL;
	// ft_putstr("\n===EEENNNDDD FIND POS====\n"); //
	return (tmps);
}


void			ft_putlststr(t_dbllist *list, int *oct)
{
	t_elem	*tmps;

	tmps = list->head;
	while (tmps != NULL)
	{
		*oct = *oct + write(1, SSTR->str, ft_strlen(SSTR->str));
		tmps = tmps->next;
	}
}

void			display_percent(int nb, t_dbllist *lst_str)
{
	t_str	sstr;
	int		i;

	ini_sstr(&sstr);
	i = 0;
	if (nb >= 1)
	{
		sstr.str = ft_strnew(nb);
		while (i < nb)
		{
			sstr.str[i] = '%';
			i++;
		}
		sstr.str[i] = '\0';
		ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
	}
}

int				stock_str(const char *format, int i, t_dbllist *lst_str)
{
	t_str	sstr;
	int		start;

	ini_sstr(&sstr);
	start = i;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	sstr.str = ft_strsub(format, start, (i - start));
	sstr.n = 1;
	ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
	// ft_strdel(&str); non sinon pb avec 42 filecheck
	return (i - 1);
}

void			transformation(t_dbllist *lst_arg, t_dbllist *lst_str,
				int * cpt_null)
{
	t_elem					*tmpa;
	static const t_action	ft_action[] = {ft_string, ft_ptr, ft_dec, ft_octal,
							ft_unsig, ft_hexalower, ft_hexaupper, ft_char,
							ft_percent};
	t_action				actions;
	t_elem					*tmps;
	char					*str;

	tmpa = lst_arg->head;
	tmps = lst_str->head;
	str = NULL;
	// ft_putstr("\n === Tranfo === \n");
	while (tmpa != NULL)
	{
		// ft_putstr("\nspec  : ");//
		// ft_putstr("Point :");
		// ft_putstr(ARG->spec);//
		// ft_putstr("\nSMOD.l  : ");//
		// ft_putnbr(SMOD.l);//
		actions = ft_action[ARG->action];
		// ft_putstr("\n actions trouve ");//
		// ft_putstr("Point :");
		// ft_putstr(ARG->spec);//
		// ft_putstr("\nSMOD.l  : ");//
		// ft_putnbr(SMOD.l);//
		tmps = find_pos(ARG->spec, lst_str);
		// ft_putstr("\n position trouve ");//
		// ft_putstr("Point :");
		// ft_putstr(ARG->spec);//
		// ft_putstr("\nSMOD.l  : ");//
		// ft_putnbr(SMOD.l);//
		SSTR->str = actions(tmpa, &str, cpt_null);
		// ft_putstr("\n actions realisees ");//
		// ft_putstr("Point :");
		// ft_putstr(ARG->spec);//
		// ft_putstr("\nSMOD.l  : ");//
		// ft_putnbr(SMOD.l);//
		// ft_putstr("\n === SSTR->str : ");//
		// ft_putstr(SSTR->str);//
		// ft_putstr("\n");//
		tmpa = tmpa->next;
	}

}
