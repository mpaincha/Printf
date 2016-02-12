/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:19:44 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:19:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action string=====\n");
	//MOD
	str = ft_strdup(mod_string(tmpa));
	//FLAGS
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_ptr(t_elem *tmpa, void *str)
{
	(void)tmpa;

	str = ft_strdup(mod_hexalower(tmpa));
	//FLAGS
	if (SFLAGS.zero == 0)
	{
		str = ft_strjoin("0x", str);
		if (SFLAGS.width != 0)
			str = define_width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			str = define_width(tmpa, str);
		str = ft_strjoin("0x", str);
	}
	return (str);
}

char	*ft_dec(t_elem *tmpa, void *str)
{
	(void)tmpa;

	//MOD
	str = ft_strdup(mod_dec(tmpa));
	//FLAGS
	if (SFLAGS.space == 1)
		str = space(tmpa, str);

	//PREC
	if (SPREC.n != 0)
		str = prec_doux(tmpa, str);
	//FLAGS
	if (SFLAGS.plus == 1)
		str = plus(tmpa, str);
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_octal(t_elem *tmpa, void *str)
{
	(void)tmpa;
	//MOD
	str = ft_strdup(mod_octal(tmpa));
	//FLAGS
	if (SFLAGS.diez == 1)
		str = diez_o(tmpa, str);
	//PREC
	if (SPREC.n != 0)
		str = prec_doux(tmpa, str);
	//FLAGS
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_unsig(t_elem *tmpa, void *str)
{
	(void)tmpa;
	//MOD
	str = ft_strdup(mod_unsig(tmpa));
	//PREC
	if (SPREC.n != 0)
		str = prec_doux(tmpa, str);
	//FLAGS
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_hexalower(t_elem *tmpa, void *str)
{
	(void)tmpa;
	//MOD
	str = ft_strdup(mod_hexalower(tmpa));
	//PREC
	if (SPREC.n != 0)
		str = prec_doux(tmpa, str);
	//FLAGS
	if (SFLAGS.diez == 1)
		str = diez_hexalower(tmpa, str);
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_hexaupper(t_elem *tmpa, void *str)
{
	(void)tmpa;
	//MOD
	str = ft_strdup(mod_hexaupper(tmpa));
	//PREC
	if (SPREC.n != 0)
		str = prec_doux(tmpa, str);
	//FLAGS
	if (SFLAGS.diez == 1)
		str = diez_hexaupper(tmpa, str);
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	//PREC
	return (str);
}

char	*ft_char(t_elem *tmpa, void *str)
{
	(void)tmpa;
	//MOD
	str = ft_strdup(mod_char(tmpa));
	//FLAGS
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	//PREC
	return (str);
}
