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
	t_elem	*tmpA;

	tmpA = list->head;
	ft_putstr("\nAFFICHAGE LISTE: \n");
	while (tmpA != NULL)
	{
		ft_putstr("\nMAILLON : \n");
		ft_putstr("arg : ");
		ft_putstr(((t_arg *)(tmpA->content))->arg);
		ft_putstr("\nflags : ");
		ft_putstr(((t_arg *)(tmpA->content))->flags);
		ft_putstr("\nnumb : ");
		ft_putnbr(((t_arg *)(tmpA->content))->numb);
		ft_putstr("\nlength : ");
		ft_putstr(((t_arg *)(tmpA->content))->length);
		ft_putstr("\nprec : ");
		ft_putstr(((t_arg *)(tmpA->content))->prec);
		ft_putstr("\nspec : ");
		ft_putstr(((t_arg *)(tmpA->content))->spec);
		ft_putstr("\ntype : ");
		ft_putstr(((t_arg *)(tmpA->content))->type);
		tmpA = tmpA->next;
	}
	ft_putchar('\n');
}
