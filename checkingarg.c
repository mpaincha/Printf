/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 18:40:33 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//&& ft_strlen(sarg->length) == 0 && ft_strlen(sarg->prec) == 0 && ft_strlen(sarg->spec) == 0

void			saveflags(char find, t_arg *sarg)
{
	if (find == '#')
		sarg->flags.diez = 1;
	else if (find == '0')
		sarg->flags.zero = 1;
	else if (find == '-')
		sarg->flags.minus = 1;
	else if (find == '+')
		sarg->flags.plus = 1;
	else if (find == ' ')
		sarg->flags.space = 1;
}

int				check_flags(const char *format, int *i, t_arg *sarg)
{
	while (format[*i] != '\0' && ft_strchr(FLAGS, format[*i]))
	{
		saveflags(format[*i], sarg);
		*i = *i + 1;
	}
	return (1);
}

int				check_number(char *str, t_arg *sarg, int *i)
{
	int		numb;

	numb = 0;
	if ((numb = ft_atoi(str)))
		sarg->flags.numb = numb;
	else
		return (0);
	*i = *i + ft_intlen(numb);
	return (1);
}

void			savemod(char find, t_arg *sarg)
{
	if (find == 'h')
		sarg->mod.h++;
	else if (find == 'l')
		sarg->mod.l++;
	else if (find == 'j')
		sarg->mod.j = 1;
	else if (find == 'z')
		sarg->mod.z = 1;
}

int				errormod(t_arg *sarg)
{
	int		i;

	i = 0;
	if (sarg->mod.h > 0)
		i++;
	if (sarg->mod.l > 0)
		i++;
	if (sarg->mod.j > 0)
		i++;
	if (sarg->mod.z > 0)
		i++;
	if (i > 1)
		return (error("mod problems"));
	else if (i == 0)
		return (0);
	return (1);
}

int				check_mod(const char *format, int *i, t_arg *sarg)
{
	ft_putstr("===check mod===");
	while (format[*i] != '\0' && ft_strchr(MOD, format[*i]))
	{
		ft_putstr("===BOUCLE check mod===");
		savemod(format[*i], sarg);
		*i = *i + 1;
	}
	if (sarg->mod.h > 0)
	{
		if (sarg->mod.h % 2 == 0)
			sarg->mod.h = 2;
		else
			sarg->mod.h = 1;
	}
	else if (sarg->mod.l > 0)
	{
		if (sarg->mod.l % 2 == 0)
			sarg->mod.l = 2;
		else
			sarg->mod.l = 1;
	}
	return (errormod(sarg));
}

int				check_prec(char point, char find, int *i,
				t_arg *sarg)
{
	if (point != '.')
		return (0);
	if (ft_strlen(sarg->prec) == 0 && ft_strlen(sarg->spec) == 0
	&& ft_strchr(PREC, find))
	{
		sarg->prec[0] = find;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

int				check_spec(char find, t_arg *sarg)
{
	if (ft_strlen(sarg->spec) == 0 && ft_strchr(SPEC, find))
	{
		sarg->spec[0] = find;
		return (1);
	}
	return (0);
}

int				checks(const char *format, int *i, t_arg *sarg)
{
	int		isave;
	int 	ret;

	isave = *i;
	ret = 0;
	if (check_flags(format, i, sarg))
		isave = *i;
	else
		*i = isave;
	if (check_number(ft_strsub(format, *i, ft_strlen(format) - *i),
	sarg, i))
		isave = *i;
	else
		*i = isave;
	if (check_prec(format[*i], format[*i + 1], i, sarg))
	{
		*i = *i + 1;
		isave = *i;
	}
	else
		*i = isave;
	ret = check_mod(format, i, sarg);
	if (ret == 1)
		isave = *i;
	else if (ret == 0)
		*i = isave;
	else
		return (-1);
	if (check_spec(format[*i], sarg))
		return (1);
	else
		return (error("Parameter problem"));
}
