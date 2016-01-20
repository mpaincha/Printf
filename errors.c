/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:50:52 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 13:50:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error(const char *msg)
{
	ft_putendl(msg);
	return (-1);
}

int		clean_lst(t_dbllist *lst_arg)
{
	if (lst_arg->head)
	{
		ft_lstdbldel(lst_arg);
		free(lst_arg);
		lst_arg = NULL;
	}
	return (0);
}
