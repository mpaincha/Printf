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

char	*define_width(t_elem *tmpa, char *str)
{
	if (SFLAGS.minus == 0)
		str = width(tmpa, str);
	else
		str = width_minus(tmpa, str);
	return (str);
}

char	*width(t_elem *tmpa, char *str)
{
	char	*new_str;
	size_t	i;
	size_t	nb;
	char	*add;
	char	tadd;

	i = 0;
	if (SFLAGS.width > ft_strlen(str))
	{
	 	nb = SFLAGS.width - ft_strlen(str);
		add = ft_strnew(nb);
	 	(SFLAGS.zero == 0) ? (tadd = ' ') : (tadd = '0');
		while (i < nb)
			add[i++] = tadd;
		add[i] = '\0';
		new_str = ft_strjoin(add, str);
		free(add);
		return (new_str);
	}
	else
		return (str);
}

char	*width_minus(t_elem *tmpa, char *str)
{
	char	*new_str;
	size_t	i;
	size_t	nb;
	char	*add;
	char	tadd;

	i = 0;
	if (SFLAGS.width > ft_strlen(str))
	{
	 	nb = SFLAGS.width - ft_strlen(str);
		add = ft_strnew(nb);
	 	(SFLAGS.zero == 0) ? (tadd = ' ') : (tadd = '0');
		while (i < nb)
			add[i++] = tadd;
		add[i] = '\0';
		new_str = ft_strcat(str, add);
		ft_strdel(&add);
		return (new_str);
	}
	else
		return (str);
}
