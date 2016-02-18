/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:41:33 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 11:41:34 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez_o(char **str)
{
	char	*tmp;

	tmp = ft_strjoin("0", *str);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexalower(char **str)
{
	char	*tmp;

	tmp = ft_strjoin("0x", *str);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexaupper(char **str)
{
	char	*tmp;

	tmp = ft_strjoin("0X", *str);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	space(char **str)
{
	char	*tmp;

	if (*str[0] != '-')
	{
		tmp = ft_strjoin(" ", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	plus(t_elem *tmpa, char **str, char *tmp)
{
	if (!(ft_strchr(*str, '-')))
	{
		if (SFLAGS.width > ft_strlen(tmp))
			*str[0] = '+';
		else
		{
			tmp = ft_strjoin("+", *str);
			// ft_strdel(str);
			*str = ft_strdup(tmp);
			// ft_strdel(&tmp);
		}
	}
}
