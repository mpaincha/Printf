/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:55:19 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/23 12:55:21 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_negative(t_elem *tmpa, char **str)
{
	char	*tmp;
	size_t		len;

	tmp = ft_strsub(*str, 1, ft_strlen(*str) - 1);
	if (SPREC.n != 0)
		prec_doux(tmpa, &tmp);
	len = ft_strlen(*str);
	if (SFLAGS.zero == 0)
	{
		minus_space(tmpa, &tmp, len);
		if (SFLAGS.width != 0)
			width(tmpa, &tmp);
		// ft_strdel(str);
		*str = ft_strdup(tmp);
		// ft_strdel(&tmp);
	}
	else
	{

		if (SFLAGS.width != 0)
			width(tmpa, &tmp);
		minus_zero(tmpa, &tmp, len);
		// ft_strdel(str);
		*str = ft_strdup(tmp);
		// ft_strdel(&tmp);
	}

}

static	void	ft_positive(t_elem *tmpa, char **str)
{
	size_t		len;

	if (SPREC.pt != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.space == 1)
		space(str);
	len = ft_strlen(*str);
	if (SFLAGS.zero == 0)
	{
		if (SFLAGS.plus == 1)
			plus_space(tmpa, str, len);
		if (SFLAGS.width != 0)
			width(tmpa, str);
	}
	else
	{

		if (SFLAGS.width != 0)
			width(tmpa, str);
		if (SFLAGS.plus == 1)
			plus_zero(tmpa, str, len);
	}
}

char	*ft_dec(t_elem *tmpa, char **str)
{
	*str = mod_dec(tmpa);
	if ((*str)[0] == '-')
		ft_negative(tmpa, str);
	else
		ft_positive(tmpa, str);
	return (*str);
}
