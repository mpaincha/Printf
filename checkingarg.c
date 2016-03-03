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

int				check_width(char *str, t_arg *sarg, int *i)
{
	int		width;

	width = 0;
	if ((width = ft_atoi(str)))
		sarg->flags.width = width;
	else
		return (0);
	*i = *i + ft_intlen(width);
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
		return (-1);
	else if (i == 0)
		return (0);
	return (1);
}

int				check_mod(const char *format, int *i, t_arg *sarg)
{
	while (format[*i] != '\0' && ft_strchr(MOD, format[*i]))
	{
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

static int		define_action(char *spec, char find)
{
	size_t		i;

	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] == find)
			return (i);
		i++;
	}
	return (-1);
}

int				check_prec(const char *format, int *i, t_arg *sarg)
{
	int		numb;
	char	*str;

	numb = 0;
	sarg->prec.pt = 1;
	str = ft_strsub(format, *i + 1, ft_strlen(format) - *i - 1);
	if ((numb = ft_atoi(str)) >= 0)
	{
		sarg->prec.n = numb;
		if (numb > 0 || (numb == 0 && str[0] == '0'))
			*i = *i + ft_intlen(numb) + 1;
		else
			*i = *i + 1;
	}
	else
	{
		sarg->prec.n = 0;
		*i = *i + 1;
	}
	return (1);
}

int				check_spec(const char *format, int *i, t_arg *sarg)
{
	// ft_putstr("\n =====CHECK SPEC ");//
	// ft_putchar(format[*i]);//
	// ft_putstr();
	if (ft_strlen(sarg->spec) == 0 && ft_strchr(SPEC, ft_tolower(format[*i])))
	{
		sarg->spec[0] = format[*i];
		sarg->spec[1] = '\0';
		sarg->action = define_action(SPEC, format[*i]);
		if (ft_isupper(format[*i]) && format[*i] != 'X')
		{
			reini_mod(sarg);
			sarg->spec[0] = ft_tolower(format[*i]);
			sarg->action = define_action(SPEC, ft_tolower(format[*i]));
			// ft_putstr("\nsarg spec : ");
			// ft_putstr(sarg->spec);
			// ft_putstr("\n");
			// ft_putstr("\nsarg mod : ");
			// ft_putnbr(sarg->mod.l);
			// ft_putstr("\n");
		}
		else if (format[*i] == 'p')
			sarg->mod.j = 1;
		return (1);
	}
	if (format[*i] == 'i')
	{
		sarg->spec[0] = 'd';
		sarg->action = define_action(SPEC, 'd');
		return (1);
	}
	if (format[*i] == '%')
	{
		if (format[*i + 1] == '%')
			sarg->spec[0] = '2';
		else
			sarg->spec[0] = '1';
		// sarg->action = 8;
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
	(check_flags(format, i, sarg)) ? (isave = *i) : (*i = isave);
	if (check_width(ft_strsub(format, *i, ft_strlen(format) - *i), sarg, i))
		isave = *i;
	else
		*i = isave;
	if (format[*i] == '.')
	{
		check_prec(format, i, sarg);
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
	if (check_spec(format, i, sarg))
	{
		// ft_putstr("debug");
		return (1);
	}
	else
	{
		if (ft_isupper(format[*i]))
		{
			sarg->spec[0] = format[*i];
			sarg->action = 9;
			return (-2);
		}
		else
			return (-1);
	}
}
