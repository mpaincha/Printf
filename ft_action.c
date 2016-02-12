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
	// ft_putstr("\n======action string=====\n");
	str = ft_strdup(mod_string(tmpa));

	return (str);
}

char	*ft_ptr(t_elem *tmpa, void *str)
{
	(void)tmpa;

	str = ft_strjoin("0x", ft_strdup(mod_hexalower(tmpa)));
	return (str);
}

char	*ft_dec(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action dec=====\n");
	str = ft_strdup(mod_dec(tmpa));
	return (str);
}

char	*ft_octal(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action octal=====\n");
	str = ft_strdup(mod_octal(tmpa));
	return (str);
}

char	*ft_unsig(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action UNSIG=====\n");
	str = ft_strdup(mod_unsig(tmpa));

	return (str);
}

char	*ft_hexalower(t_elem *tmpa, void *str)
{
	(void)tmpa;
	if (SFLAGS.diez == 1)
		str = ft_strjoin("0x", ft_strdup(mod_hexalower(tmpa)));
	else
		str = ft_strdup(mod_hexalower(tmpa));

	return (str);
}

char	*ft_hexaupper(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action hexaupper=====\n");
	str = ft_strdup(mod_hexaupper(tmpa));

	return (str);
}

char	*ft_char(t_elem *tmpa, void *str)
{
	(void)tmpa;
	// ft_putstr("\n======action char=====\n");
	str = ft_strdup(mod_char(tmpa));
	return (str);
}
