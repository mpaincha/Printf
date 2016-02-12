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

// char	*width
