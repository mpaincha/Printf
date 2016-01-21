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
	va_list		ap;
	va_start(ap, format);
	t_dbllist	*lst_arg;

	lst_arg = ft_lstdblnew();
	//recover_arg(ap, lst_arg);
	display(format, lst_arg);
	 if (lst_arg->head)
	 	ft_putlst(lst_arg); // FREE LA LISTE SI PB PARAMETRE
	// open(ap, lst_arg);
	//if (lst_arg->length > 0)
	//	return (error("il manque un ou des parametres"));
	//printf("Il y a %d arg %%\n", recovery_arg(format));
	//va_arg(ap, ); //en deuxieme, il faut le type de parametre  qu'on recupere,
	//le type du ap en cours
	va_end(ap); //il faut terminer par ca obligatoirement
	return (1);
}
