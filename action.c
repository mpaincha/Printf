/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:45:11 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 12:45:13 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action string=====\n");
	// if (ARG->flags.zero == 1)
	// 	zero(tmpa, str);
	// else if (ARG->flags.minus == 1)
	// 	minus(tmpa, str);
	// if (ARG->flags.plus == 1)
	// 	plus(tmpa, str);
	// else if (ARG->flags.space == 1)
	// 	space(tmpa, str);
	return (str);
}

char	*ft_ptr(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action ptr=====\n");
	return (str);
}

char	*ft_dec(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action dec=====\n");
	return (str);
}

char	*ft_octal(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action octal=====\n");
	return (str);
}

char	*ft_unsig(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action UNSIG=====\n");
	return (str);
}

char	*ft_hexalower(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action hexalower=====\n");
	return (str);
}

char	*ft_hexaupper(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action hexaupper=====\n");
	return (str);
}

char	*ft_char(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action char=====\n");
	return (str);
}
