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

char	*ft_string(t_elem *tmpa, char **str)
{
	*str = mod_string(tmpa);
	if (SPREC.n != 0)
		prec_s(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_ptr(t_elem *tmpa, char **str)
{
	char	*tmp;

	*str = mod_hexalower(tmpa);
	if (SFLAGS.zero == 0)
	{
		tmp = ft_strjoin("0x", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, str);
		tmp = ft_strsub(*str, 2, ft_strlen(*str) - 2);
		tmp = ft_strjoin("0x", tmp);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	return (*str);
}

char	*ft_dec(t_elem *tmpa, char **str)
{
	char *tmp;

	*str = mod_dec(tmpa);
	tmp = ft_strdup(*str);
	if (SFLAGS.space == 1)
		space(str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	if (SFLAGS.plus == 1)
		plus(tmpa, str, tmp);
	return (*str);
}

char	*ft_octal(t_elem *tmpa, char **str)
{
	*str = mod_octal(tmpa);
	if (SFLAGS.diez == 1)
		diez_o(str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_unsig(t_elem *tmpa, char **str)
{
	*str = mod_unsig(tmpa);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_hexalower(t_elem *tmpa, char **str)
{
	*str = mod_hexalower(tmpa);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.diez == 1)
		diez_hexalower(str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_hexaupper(t_elem *tmpa, char **str)
{
	*str = mod_hexaupper(tmpa);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.diez == 1)
		diez_hexaupper(str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_char(t_elem *tmpa, char **str)
{
	*str = mod_char(tmpa);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_percent(t_elem *tmpa, char **str)
{
	if (ARG->spec == "2")
		*str = ft_strdup("%%");
	else
		*str = ft_strdup("%");
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}
