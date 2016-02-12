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

char	*diez_o(t_elem *tmpa, char *str)
{
	char	*new_str;

	new_str = ft_strjoin("0", str);
	return (new_str);
}

char	*diez_hexalower(t_elem *tmpa, char *str)
{
	char	*new_str;

	new_str = ft_strjoin("0x", str);
	return (new_str);
}

char	*diez_hexaupper(t_elem *tmpa, char *str)
{
	char	*new_str;

	new_str = ft_strjoin("0X", str);
	return (new_str);
}

char	*space(t_elem *tmpa, char *str)
{
	char	*new_str;

	if (str[0] == '-')
		return (str);
	else
		new_str = ft_strjoin(" ", str);
	return (new_str);
}

// char	*minus(t_elem *tmpa, char *str)
// {

// }

char	*plus(t_elem *tmpa, char *str)
{
	char	*new_str;

	if (str[0] != '-')
		new_str = ft_strjoin("+", str);
	else
		return (str);
	return (new_str);
}

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
	size_t	nb_z;
	char	*add;
	char	tadd;

	i = 0;
	if (SFLAGS.width > ft_strlen(str))
	{
	 	nb_z = SFLAGS.width - ft_strlen(str);
		add = ft_strnew(nb_z);
	 	(SFLAGS.zero == 0) ? (tadd = ' ') : (tadd = '0');
		while (i < nb_z)
			add[i++] = tadd;
		add[i] = '\0';
		new_str = ft_strjoin(add, str);
		ft_strdel(&add);
		return (new_str);
	}
	else
		return (str);
}

char	*width_minus(t_elem *tmpa, char *str)
{
	char	*new_str;
	size_t	i;
	size_t	nb_z;
	char	*add;
	char	tadd;

	i = 0;
	if (SFLAGS.width > ft_strlen(str))
	{
	 	nb_z = SFLAGS.width - ft_strlen(str);
		add = ft_strnew(nb_z);
	 	(SFLAGS.zero == 0) ? (tadd = ' ') : (tadd = '0');
		while (i < nb_z)
			add[i++] = tadd;
		add[i] = '\0';
		new_str = ft_strcat(str, add);
		ft_strdel(&add);
		return (new_str);
	}
	else
		return (str);
}
