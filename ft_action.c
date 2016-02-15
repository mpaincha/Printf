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

char	*ft_string(t_elem *tmpa)
{
	char	*str;

	// ft_putstr("\n======action string=====\n");
	//MOD
	str = mod_string(tmpa);
	//PREC
	// if (SPREC.n != 0)
	// 	str = prec_s(tmpa, str);
	//FLAGS
	// if (SFLAGS.width != 0)
	// 	str = define_width(tmpa, str);
	return (str);
}

char	*ft_ptr(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	str = mod_hexalower(tmpa);
	//FLAGS
	if (SFLAGS.zero == 0)
	{
		str = ft_strjoin("0x", str);
		if (SFLAGS.width != 0)
		{
			tmp = str;
			str = define_width(tmpa, tmp);
			free(tmp);
		}
	}
	else
	{
		if (SFLAGS.width != 0)
		{
			tmp = str;
			str = define_width(tmpa, tmp);
			free(tmp);
		}
		str = ft_strsub(str, 2, ft_strlen(str) - 2);
		str = ft_strjoin("0x", str);
	}
	return (str);
}

char	*ft_dec(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	//MOD
	str = mod_dec(tmpa);
	//FLAGS
	if (SFLAGS.space == 1)
	{
		tmp = str;
		str = space(tmpa, tmp);
		free(tmp);
	}

	//PREC
	if (SPREC.n != 0)
	{
		tmp = str;
		str = prec_doux(tmpa, tmp);
		free(tmp);
	}
	//FLAGS
	if (SFLAGS.plus == 1)
	{
		tmp = str;
		str = plus(tmpa, tmp);
		free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		tmp = str;
		str = define_width(tmpa, tmp);
		free(tmp);
	}
	return (str);
}

char	*ft_octal(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	//MOD
	str = mod_octal(tmpa);
	//FLAGS
	if (SFLAGS.diez == 1)
	{
		tmp = str;
		str = diez_o(tmpa, tmp);
		free(tmp);
	}
	//PREC
	if (SPREC.n != 0)
	{
		tmp = str;
		str = prec_doux(tmpa, tmp);
		free(tmp);
	}
	//FLAGS
	if (SFLAGS.width != 0)
	{
		tmp = str;
		str = define_width(tmpa, tmp);
		free(tmp);
	}
	return (str);
}

char	*ft_unsig(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	//MOD
	str = mod_unsig(tmpa);
	//PREC
	if (SPREC.n != 0)
	{
		tmp = str;
		str = prec_doux(tmpa, tmp);
		free(tmp);
	}
	//FLAGS
	if (SFLAGS.width != 0)
	{
		tmp = str;
		str = define_width(tmpa, tmp);
		free(tmp);
	}
	return (str);
}

char	*ft_hexalower(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	//MOD
	str = mod_hexalower(tmpa);
	//PREC
	if (SPREC.n != 0)
	{
		tmp = str;
		str = prec_doux(tmpa, tmp);
		free(tmp);
	}
	//FLAGS
	if (SFLAGS.diez == 1)
	{
		tmp = str;
		str = diez_hexalower(tmpa, tmp);
		free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		tmp = str;
		str = define_width(tmpa, tmp);
		free(tmp);
	}
	return (str);
}

char	*ft_hexaupper(t_elem *tmpa)
{
	char	*str;
	char	*tmp;

	(void)tmpa;
	//MOD
	str = mod_hexaupper(tmpa);
	//PREC
	if (SPREC.n != 0)
	{
		tmp = str;
		str = prec_doux(tmpa, tmp);
		free(tmp);
	}
	//FLAGS
	if (SFLAGS.diez == 1)
	{
		tmp = str;
		str = diez_hexaupper(tmpa, tmp);
		free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		tmp = str;
		str = define_width(tmpa, tmp);
		free(tmp);
	}
	//PREC
	return (str);
}

char	*ft_char(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	(void)tmpa;
	//MOD
	str = mod_char(tmpa);
	//FLAGS
	if (SFLAGS.width != 0)
	{

		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	//PREC
	return (str);
}
