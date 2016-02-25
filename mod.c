/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:39:59 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:40:00 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mod_string(t_elem *tmpa)
{
	// ft_putstr("\n  === MOD STRING\n"); //
	// 	ft_putstr("Point :");
	// 	ft_putstr(ARG->spec);//
	// 	ft_putstr("\nSMOD.l  : ");//
	// 	ft_putnbr(SMOD.l);//
	if (SMOD.l == 1)
	{
		// ft_putstr("\nwchar\n"); //
		return (ft_strdup(ft_wchar_str(tmpa)));
	}
	// ft_putstr("\nnot if\n"); //
	return (ft_strdup((char *)ARG->arg));
}

char	*mod_dec(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_imax((signed short)ARG->arg, 10));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax((signed char)ARG->arg, 10));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax((long)ARG->arg, 10));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax((long long)ARG->arg, 10));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax((intmax_t)ARG->arg, 10));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax((ssize_t)ARG->arg, 10));
	else
		return (ft_itoabase_imax((int)ARG->arg, 10));
}

char	*mod_octal(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax((unsigned short)ARG->arg, 8));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax((unsigned char)ARG->arg, 8));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax((unsigned long)ARG->arg, 8));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax((unsigned long long)ARG->arg, 8));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax((uintmax_t)ARG->arg, 8));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax((size_t)ARG->arg, 8));
	else
		return (ft_itoabase_uimax((unsigned int)ARG->arg, 8));
}

char	*mod_unsig(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax((unsigned short)ARG->arg, 10));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax((unsigned char)ARG->arg, 10));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax((unsigned long)ARG->arg, 10));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax((unsigned long long)ARG->arg, 10));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax((uintmax_t)ARG->arg, 10));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax((size_t)ARG->arg, 10));
	else
		return (ft_itoabase_uimax((unsigned int)ARG->arg, 10));
}

char	*mod_hexa(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax((unsigned short)ARG->arg, 16));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax((unsigned char)ARG->arg, 16));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax((unsigned long)ARG->arg, 16));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax((unsigned long long)ARG->arg, 16));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax((uintmax_t)ARG->arg, 16));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax((size_t)ARG->arg, 16));
	else
		return (ft_itoabase_uimax((unsigned int)ARG->arg, 16));
}

char	*mod_char(t_elem *tmpa)
{
	char	*str;

	if (SMOD.l == 1)
		return (ft_strdup(mask((wchar_t)ARG->arg)));
	str = ft_strnew(1);
	str[0] = (char)ARG->arg;
	str[1] = '\0';
	return (str);
}
