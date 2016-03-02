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

char	*ft_string(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;

	if (ARG->arg == NULL)
		*str = ft_strdup("(null)");
	else
		*str = mod_string(tmpa);
	if (SPREC.pt != 0)
		prec_s(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_ptr(t_elem *tmpa, char **str, int *cpt_null)
{
	char	*tmp;

	(void)cpt_null;
	*str = mod_hexa(tmpa);
	if (ft_atoi(*str) == 0 && SPREC.pt == 1)
	{
		ft_strdel(str);
		*str = ft_strdup("");
	}
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
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
	ft_strlower(str);
	return (*str);
}

char	*ft_octal(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("");
	else
		*str = mod_octal(tmpa);
	if (SFLAGS.diez == 1)
		diez_o(str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	if ((*str)[0] == '\0' && SPREC.pt == 0)
	{
		ft_strdel(str);
		*str = ft_strdup("0");
	}
	return (*str);
}

char	*ft_unsig(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	*str = mod_unsig(tmpa);
	if (ft_atoi(*str) == 0 && SPREC.pt == 1)
	{
		ft_strdel(str);
		*str = ft_strdup("");
	}
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_hexalower(t_elem *tmpa, char **str, int *cpt_null)
{
	size_t	len;

	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("");
	else
		*str = mod_hexa(tmpa);
	len = ft_strlen(*str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
	{
		if (SFLAGS.diez == 1 && ARG->arg != NULL)
			diez_hexaupper(str, len, tmpa);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, str);
		if (SFLAGS.diez == 1 && ARG->arg != NULL)
			diez_hexaupper_zero(str, len, tmpa);
	}
	ft_strlower(str);
	if ((*str)[0] == '\0' && SPREC.pt == 0)
	{
		ft_strdel(str);
		*str = ft_strdup("0");
	}
	return (*str);
}

char	*ft_hexaupper(t_elem *tmpa, char **str, int *cpt_null)
{
	size_t	len;
	int		i;

	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("");
	else
		*str = mod_hexa(tmpa);
	len = ft_strlen(*str);
	i = 0;
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
	{
		if (SFLAGS.diez == 1 && ARG->arg != NULL)
			diez_hexaupper(str, len, tmpa);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, str);
		if (SFLAGS.diez == 1 && ARG->arg != NULL)
			diez_hexaupper_zero(str, len, tmpa);
	}
	if ((*str)[0] == '\0' && SPREC.pt == 0)
	{
		ft_strdel(str);
		*str = ft_strdup("0");
	}
	return (*str);
}

char	*ft_char(t_elem *tmpa, char **str, int *cpt_null)
{
	if (ARG->arg == NULL)
	{
		*str = ft_strdup("");
		*cpt_null = *cpt_null + 1;
	}
	else
		*str = mod_char(tmpa);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}

char	*ft_percent(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	if (ARG->spec == "2")
		*str = ft_strdup("%%");
	else
		*str = ft_strdup("%");
	if (SFLAGS.width != 0)
		width(tmpa, str);
	return (*str);
}
