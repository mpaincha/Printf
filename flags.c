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
			if (i > 0)
				(*str)[i - 1] = '+';
			else
			{
				tmp = ft_strjoin("+", *str);
				// ft_strdel(str);
				*str = ft_strdup(tmp);
			}
			// ft_putstr("str plus :");
			// ft_putstr(*str);
			// ft_putstr("/\n");
		}
		else
		{
			tmp = ft_strjoin("+", *str);
			// ft_strdel(str);
			*str = ft_strdup(tmp);
			// ft_putstr("str plus ELSE:");
			// ft_putstr(*str);
			// ft_putstr("/\n");
			// ft_strdel(&tmp);
		}
	}
}
