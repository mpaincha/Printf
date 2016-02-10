/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:19:44 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:19:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(t_elem *tmpa, void *str)
{
	(void)tmpa;
	ft_putstr("\n======action string=====\n");

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
	mod_dec(tmpa, str);

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
