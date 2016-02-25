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
	if (ARG->arg != NULL)
		len = ft_strlen(*str);
	else if (ARG->spec[0] == 'c')
		len = 1;
	else if (ARG->spec[0] == 'd')
		len = 1;
	if (SFLAGS.width > len)
	{
		nb = SFLAGS.width - len;
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
