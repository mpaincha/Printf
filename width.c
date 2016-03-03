/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:13:17 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/12 17:13:20 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	width_null(t_elem *tmpa, size_t *len)
{
	if (ARG->spec[0] == 'c' || ARG->spec[0] == '%'
		|| !(ft_strchr(SPEC, ARG->spec[0])))
		*len = 1;
	else if (ARG->spec[0] == 'd')
	{
		if (SFLAGS.space == 0)
		{
			if (SPREC.pt != 0)
				*len = SPREC.n;
			else
				*len = 1;
		}
		else
		{
			if (SPREC.pt != 0)
				*len = SPREC.n  + 1;
			else
				*len = 2;
		}
	}
	else if (ARG->spec[0] == 'p')
	{
		if (SPREC.pt != 0)
			*len = 3;
		else
			*len = 1;
	}
}

void	width(t_elem *tmpa, char **str)
{
	char	*tmp;
	size_t	i;
	size_t	nb;
	char	*add;
	char	tadd;
	size_t	len;

	i = 0;
	tmp = NULL;
	add = NULL;
	len = 0;
	if (ARG->arg == NULL  && ft_strlen(*str) == 0)
		width_null(tmpa, &len);
	else
		len = ft_strlen(*str);
	if (SFLAGS.width > len)
	{
		// ft_putstr("\nlen :"); //
		// ft_putnbr(len);
		// ft_putstr("\n"); //

		nb = SFLAGS.width - len;

		// ft_putstr("\nb :"); //
		// ft_putnbr(nb);
		// ft_putstr("\n"); //

		add = ft_strnew(nb);
		(SFLAGS.zero == 0) ? (tadd = ' ') : (tadd = '0');
		while (i < nb)
			add[i++] = tadd;
		add[i] = '\0';
		if (SFLAGS.minus == 0)
			tmp = ft_strjoin(add, *str);
		else
			tmp = ft_strjoin(*str, add);
		ft_strdel(str);
		ft_strdel(&add);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}
