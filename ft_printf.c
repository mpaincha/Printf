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

	display(format);
	//printf("Il y a %d arg %%\n", recovery_arg(format));
	//va_arg(ap, ); //en deuxieme, il faut le type de parametre  qu'on recupere,
	//le type du ap en cours
	va_end(ap); //il faut terminer par ca obligatoirement
	return (1);
}
