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

void	prec_s(t_elem *tmpa, char **str)
{
	char	*tmp;

	if (SPREC.n != 0 && SPREC.n < (int)ft_strlen(*str))
	{
		tmp = ft_strnew(SPREC.n + 1);
		tmp = ft_strncpy(tmp, *str, SPREC.n);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}

}

void	prec_doux(t_elem *tmpa, char **str)
{
	char	*tmp;
	size_t	i;
	size_t	nb;
	char	*add;

	i = 0;
	if (SPREC.n != -1 && (SPREC.n > (int)ft_strlen(*str)))
	{
	 	nb = SPREC.n - (int)ft_strlen(*str);
		add = ft_strnew(nb);
		while (i < nb)
			add[i++] = '0';
		add[i] = '\0';
		tmp = ft_strjoin(add, *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strdel(&add);
	}
}
