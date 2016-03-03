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

void	space_beforewidth(char **str)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		tmp = ft_strjoin(" ", *str);
		*str = ft_strdup(tmp);
	}
}

void	space_afterwidth(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		if (SFLAGS.width > len)
		{
			(*str)[0] = ' ';
			ft_strdel(&tmp);
		}
		else
		{
			tmp = ft_strjoin(" ", *str);
			*str = ft_strdup(tmp);
		}
		// ft_putstr("str :");
		// ft_putstr(*str);
		// ft_putstr("\n");
		// ft_strdel(&tmp);
	}
}

void	plus_space(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (SFLAGS.width > len)
	{
		while (!(ft_isdigit((*str)[i])))
			i++;
		if (i > 0)
		{
			(*str)[i - 1] = '+';
			return ;
		}
	}
	tmp = ft_strjoin("+", *str);
	// ft_strdel(str);
	*str = ft_strdup(tmp);
	// ft_strdel(&tmp);
}

void	plus_zero(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (SFLAGS.width > len)
		(*str)[0] = '+';
	else
	{
		tmp = ft_strjoin("+", *str);
		// ft_strdel(str);
		*str = ft_strdup(tmp);
		// ft_strdel(&tmp);
	}
}

void	minus_space(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (SFLAGS.width > len)
	{
		while (!(ft_isdigit((*str)[i])))
			i++;
		if (i > 0)
		{
			(*str)[i - 1] = '-';
			return ;
		}
	}
	tmp = ft_strjoin("-", *str);
	// ft_strdel(str);
	*str = ft_strdup(tmp);
	// ft_strdel(&tmp);
}

void	minus_zero(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (SFLAGS.width > len)
		(*str)[0] = '-';
	else
	{
		tmp = ft_strjoin("-", *str);
		// ft_strdel(str);
		*str = ft_strdup(tmp);
		// ft_strdel(&tmp);
	}
}

