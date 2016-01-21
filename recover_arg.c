/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 12:09:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/21 12:09:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recover_arg(va_list ap, t_dbllist *lst_arg)
{
	t_arg	sarg;
	void	*arg;

	ini_sarg(&sarg);
	arg = (void *)1;
	while (1)
	{
		ini_sarg(&sarg);
		arg = va_arg(ap, void *);
		if (arg == NULL)
			break ;
		sarg.arg = arg;
		ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
	}
}
