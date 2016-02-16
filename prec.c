/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:13:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/12 17:13:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_s(t_elem *tmpa, char *str)
{
	char	*new_str;

	new_str = ft_strnew(SPREC.n + 1);
	if (SPREC.n != 0 && SPREC.n < ft_strlen(str))
	{
		new_str = ft_strncpy(new_str, str, SPREC.n);
		return (new_str);
	}
	return (str);
}

char	*prec_doux(t_elem *tmpa, char *str)
{
	char	*new_str;
	size_t	i;
	size_t	nb;
	char	*add;

	i = 0;
	if (SPREC.n != -1 && (SPREC.n > ft_strlen(str)))
	{
	 	nb = SPREC.n - ft_strlen(str);
		add = ft_strnew(nb);
		while (i < nb)
			add[i++] = '0';
		add[i] = '\0';
		new_str = ft_strjoin(add, str);
		ft_strdel(&add);
		return (new_str);
	}
	else
		return (str);
}
