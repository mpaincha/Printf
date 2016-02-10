/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:54:26 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 11:54:28 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_sarg(t_arg *sarg)
{
	ft_putstr("\n====INI SARG====\n");
	sarg->arg = NULL;
	sarg->flags.diez = 0;
	sarg->flags.zero = 0;
	sarg->flags.minus = 0;
	sarg->flags.plus = 0;
	sarg->flags.space = 0;
	sarg->flags.numb = 0;
	sarg->mod.h = 0;
	sarg->mod.l = 0;
	sarg->mod.j = 0;
	sarg->mod.z = 0;
	sarg->mod.mod = -1;
	sarg->prec.pt = 0;
	sarg->prec.n = -1;
	sarg->spec = ft_strnew(sizeof(char) * 1);
	sarg->action = -1;
}
