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

char	*width(t_elem *tmpa, char *str)
{
	char	*new_str;
	size_t	i;
	size_t	nb_z;
	char	*add;

	i = 0;
	if (SFLAGS.width > ft_strlen(str))
	{
	 	if (SFLAGS.zero == 0)
		{
			nb_z = SFLAGS.width - ft_strlen(str);
			add = ft_strnew(nb_z);
			while (i < nb_z)
				add[i++] = ' ';
			add[i] = '\0';
			new_str = ft_strjoin(add, str);
			return (new_str);
		}
		else
		{
			nb_z = SFLAGS.width - ft_strlen(str);
			add = ft_strnew(nb_z);
			while (i < nb_z)
				add[i++] = '0';
			add[i] = '\0';
			new_str = ft_strjoin(add, str);
			return (new_str);
		}
	}
	else
		return (str);
}
