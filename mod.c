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
	if (SMOD.l == 1)
		return ("a traiter");
	return ((char *)ARG->arg);
}

char	*mod_ptr(t_elem *tmpa)
{
	(void)tmpa;

	return ("a traiter");
	// return (ft_itoabase_imax((void *)ARG->arg, 16));
}

char	*mod_dec(t_elem *tmpa)
{
	// ft_putstr("\n=== MOD DEC ===\n");
	// ft_putstr(ft_itoabase_imax((long)ARG->arg, 10));
	// ft_putstr("\n");
	// ft_putnbr(SMOD.l);
	// ft_putstr("\n");
	if (SMOD.h == 1)
		return (ft_itoabase_imax((signed short)ARG->arg, 10));
// probleme avec les negatifs
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
		return (ft_itoabase_imax((unsigned short)ARG->arg, 8));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax((unsigned char)ARG->arg, 8));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax((unsigned long)ARG->arg, 8));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax((unsigned long long)ARG->arg, 8));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax((intmax_t)ARG->arg, 8));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax((size_t)ARG->arg, 8));
	else
		return (ft_itoabase_imax((unsigned int)ARG->arg, 8));
}

char	*mod_unsig(t_elem *tmpa)
{
	ft_putstr("\n=== MOD DEC ===\n");
	ft_putstr(ft_itoabase_imax((long)ARG->arg, 10));
	ft_putstr("\n");
	ft_putnbr(SMOD.l);
	ft_putstr("\n");
	if (SMOD.h == 1)
		return (ft_itoabase_imax((unsigned short)ARG->arg, 10));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax((unsigned char)ARG->arg, 10));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax((unsigned long)ARG->arg, 10));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax((unsigned long long)ARG->arg, 10));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax((intmax_t)ARG->arg, 10));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax((size_t)ARG->arg, 10));
	else
		return (ft_itoabase_imax((unsigned int)ARG->arg, 10));
}

char	*mod_hexalower(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_imax_x((unsigned short)ARG->arg, 16));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax_x((unsigned char)ARG->arg, 16));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax_x((unsigned long)ARG->arg, 16));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax_x((unsigned long long)ARG->arg, 16));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax_x((intmax_t)ARG->arg, 16));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax_x((size_t)ARG->arg, 16));
	else
		return (ft_itoabase_imax_x((unsigned int)ARG->arg, 16));
}

char	*mod_hexaupper(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_imax((unsigned short)ARG->arg, 16));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax((unsigned char)ARG->arg, 16));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax((unsigned long)ARG->arg, 16));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax((unsigned long long)ARG->arg, 16));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax((intmax_t)ARG->arg, 16));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax((size_t)ARG->arg, 16));
	else
		return (ft_itoabase_imax((unsigned int)ARG->arg, 16));
}

char	*mod_char(t_elem *tmpa)
{
	if (SMOD.l == 1)
		return ("a traiter");
	return (ft_itoabase_imax((int)ARG->arg, 10));
}
