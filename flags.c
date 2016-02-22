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

void	diez_hexalower(char **str, size_t len, size_t w)
{
	char	*tmp;

	tmp = NULL;
	if (w > len)
	{
		if (w - len == 1)
		{
			*str[0] = 'x';
			tmp = ft_strjoin("0", *str);
			ft_strdel(str);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
		{
			(*str)[0] = '0';
			(*str)[1] = 'x';
			ft_strdel(&tmp);
		}

	}
	else
	{
		tmp = ft_strjoin("0x", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	diez_hexaupper(char **str, size_t len, size_t w)
{
	char	*tmp;

	tmp = NULL;
	if (w > len)
	{
		if (w - len == 1)
		{
			*str[0] = 'x';
			tmp = ft_strjoin("0", *str);
			ft_strdel(str);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
		{
			(*str)[0] = '0';
			(*str)[1] = 'x';
			ft_strdel(&tmp);
		}

	}
	else
	{
		tmp = ft_strjoin("0x", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	space(char **str)
{
	char	*tmp;

	if ((*str)[0] != '-')
	{

		tmp = ft_strjoin(" ", *str);
		// ft_strdel(str);
		*str = ft_strdup(tmp);
		// ft_strdel(&tmp);
	}
}

void	plus(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(ft_strchr(*str, '-')))
	{
		if (SFLAGS.width > len)
		{
			while (!(ft_isdigit((*str)[i])))
				i++;
			(*str)[i - 1] = '+';
		}
		else
		{
			tmp = ft_strjoin("+", *str);
			// ft_strdel(str);
			*str = ft_strdup(tmp);
			// ft_strdel(&tmp);
		}
	}
}
