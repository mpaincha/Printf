/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:45:11 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 12:45:13 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	action_flags(t_elem *tmpa,t_dbllist *lst_str, char *str)
{
	// (void)tmpa;
	(void)lst_str;
	// (void)str;
	ft_putstr("\n======action FLAGS=====\n");
	if (ARG->flags.diez == 1)
		diez(tmpa, str);
	// if (ARG->flags.zero == 1)
	// 	zero(tmpa, str);
	// else if (ARG->flags.minus == 1)
	// 	minus(tmpa, str);
	// if (ARG->flags.plus == 1)
	// 	plus(tmpa, str);
	// else if (ARG->flags.space == 1)
	// 	space(tmpa, str);
}

void	action_mod(t_elem *tmpa,t_dbllist *lst_str, char *str)
{
		(void)tmpa;
	(void)lst_str;
	(void)str;
	ft_putstr("\n======action LENGTH=====\n");
}

void	action_prec(t_elem *tmpa,t_dbllist *lst_str, char *str)
{
		(void)tmpa;
	(void)lst_str;
	(void)str;
	ft_putstr("\n======action PREC=====\n");

}

void	action_spec(t_elem *tmpa,t_dbllist *lst_str, char *str)
{
		(void)tmpa;
	(void)lst_str;
	(void)str;
	ft_putstr("\n======action SPEC=====\n");

}
