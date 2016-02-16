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

	str = mod_string(tmpa);
	if (SPREC.n != 0)
		str = prec_s(tmpa, str);
	if (SFLAGS.width != 0)
		str = define_width(tmpa, str);
	return (str);
}

char	*ft_ptr(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	str = mod_hexalower(tmpa);
	if (SFLAGS.zero == 0)
	{
		str = ft_strjoin("0x", str);
		if (SFLAGS.width != 0)
		{
			// tmp = str;
			str = define_width(tmpa, str);
			// free(tmp);
		}
	}
	else
	{
		if (SFLAGS.width != 0)
		{
			// tmp = str;
			str = define_width(tmpa, str);
			// free(tmp);
		}
		str = ft_strsub(str, 2, ft_strlen(str) - 2);
		str = ft_strjoin("0x", str);
	}
	return (str);
}

char	*ft_dec(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	str = mod_dec(tmpa);
	if (SFLAGS.space == 1)
	{
		// tmp = str;
		space(tmpa, str);
		// free(tmp);
	}
	if (SPREC.n != 0)
	{
		// tmp = str;
		str = prec_doux(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.plus == 1)
	{
		// tmp = str;
		str = plus(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}

char	*ft_octal(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	str = mod_octal(tmpa);
	if (SFLAGS.diez == 1)
	{
		// tmp = str;
		str = diez_o(tmpa, str);
		// free(tmp);
	}
	if (SPREC.n != 0)
	{
		// tmp = str;
		str = prec_doux(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}

char	*ft_unsig(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	str = mod_unsig(tmpa);
	if (SPREC.n != 0)
	{
		// tmp = str;
		str = prec_doux(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}

char	*ft_hexalower(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	str = mod_hexalower(tmpa);
	if (SPREC.n != 0)
	{
		// tmp = str;
		str = prec_doux(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.diez == 1)
	{
		// tmp = str;
		str = diez_hexalower(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}

char	*ft_hexaupper(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	(void)tmpa;
	str = mod_hexaupper(tmpa);
	if (SPREC.n != 0)
	{
		// tmp = str;
		str = prec_doux(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.diez == 1)
	{
		// tmp = str;
		str = diez_hexaupper(tmpa, str);
		// free(tmp);
	}
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}

char	*ft_char(t_elem *tmpa)
{
	char	*str;
	// char	*tmp;

	(void)tmpa;
	str = mod_char(tmpa);
	if (SFLAGS.width != 0)
	{
		// tmp = str;
		str = define_width(tmpa, str);
		// free(tmp);
	}
	return (str);
}
