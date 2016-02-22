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

	*str = mod_hexa(tmpa);
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

static	void	ft_negative(t_elem *tmpa, char **str)
{
	char	*tmp;

	tmp = ft_strsub(*str, 1, ft_strlen(*str) - 1);
	if (SFLAGS.space == 1)
		space(&tmp);
	if (SPREC.n != 0)
		prec_doux(tmpa, &tmp);
	if (SFLAGS.width != 0)
	{
		width(tmpa, &tmp);
		if (SFLAGS.width > ft_strlen(*str))
		{
			tmp[0] = '-';
			ft_strdel(str);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
			return ;
		}
	}
	ft_strdel(str);
	*str = ft_strjoin("-", tmp);
	ft_strdel(&tmp);

}

static	void	ft_positive(t_elem *tmpa, char **str)
{
	size_t		len;

	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.space == 1)
		space(str);
	len = ft_strlen(*str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	if (SFLAGS.plus == 1)
		plus(tmpa, str, len);
}

char	*ft_dec(t_elem *tmpa, char **str)
{
	*str = mod_dec(tmpa);
	if ((*str)[0] != '-' || ((*str)[0] == '-' && SFLAGS.zero == 0))
		ft_positive(tmpa, str);
	else
		ft_negative(tmpa, str);
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
	size_t	len;

	*str = mod_hexa(tmpa);
	len = ft_strlen(*str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
	{
		if (SFLAGS.diez == 1)
			diez_hexaupper(str, len, tmpa);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, str);
		if (SFLAGS.diez == 1)
			diez_hexaupper_zero(str, len, tmpa);
	}
	ft_strlower(str);
	return (*str);
}

char	*ft_hexaupper(t_elem *tmpa, char **str)
{
	size_t	len;
	int		i;

	*str = mod_hexa(tmpa);
	len = ft_strlen(*str);
	i = 0;
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
	{
		if (SFLAGS.diez == 1)
			diez_hexaupper(str, len, tmpa);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, str);
		if (SFLAGS.diez == 1)
			diez_hexaupper_zero(str, len, tmpa);
	}
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
