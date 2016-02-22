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
		if (SFLAGS.width > len && SFLAGS.zero == 1)
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
