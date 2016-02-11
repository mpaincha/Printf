/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:57 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/20 18:47:00 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlst(t_dbllist	*list)
{
	t_elem	*tmpa;

	tmpa = list->head;
	ft_putstr("\nAFFICHAGE LISTE: \n");
	while (tmpa != NULL)
	{
		ft_putstr("\nMAILLON : \n");
		// ft_putstr("arg : ");
		// ft_putstr(((t_arg *)(tmpa->content))->arg);
		ft_putstr("\nflags, diez : ");
		ft_putnbr(SFLAGS.diez);
		ft_putstr("\nflags, zero : ");
		ft_putnbr(SFLAGS.zero);
		ft_putstr("\nflags, minus : ");
		ft_putnbr(SFLAGS.minus);
		ft_putstr("\nflags, plus : ");
		ft_putnbr(SFLAGS.plus);
		ft_putstr("\nflags, space : ");
		ft_putnbr(SFLAGS.space);
		ft_putstr("\nflags, numb : ");
		ft_putnbr(SFLAGS.numb);
		ft_putstr("\nMOD, h : ");
		ft_putnbr(SMOD.h);
		ft_putstr("\nMOD, l : ");
		ft_putnbr(SMOD.l);
		ft_putstr("\nMOD, j : ");
		ft_putnbr(SMOD.j);
		ft_putstr("\nMOD, z : ");
		ft_putnbr(SMOD.z);
		ft_putstr("\nprec.pt : ");
		ft_putnbr(SPREC.pt);
		ft_putstr("\nprec.n : ");
		ft_putnbr(SPREC.n);
		ft_putstr("\nspec : ");
		ft_putstr(((t_arg *)(tmpa->content))->spec);
		ft_putstr("\naction : ");
		ft_putnbr(((t_arg *)(tmpa->content))->action);
		tmpa = tmpa->next;
	}
	ft_putchar('\n');
}
