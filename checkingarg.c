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
	if (find == '0')
		sarg->flags.zero = 1;
	if (find == '-')
		sarg->flags.minus = 1;
	if (find == '+')
		sarg->flags.plus = 1;
	if (find == ' ')
		sarg->flags.space = 1;
}

int				check_flags(const char *format, int *i, t_arg *sarg)
{
	while (format[*i] != '\0' && ft_strlen(sarg->length) == 0 && ft_strlen(sarg->prec) == 0
	&& ft_strlen(sarg->spec) == 0 && ft_strchr(FLAGS, format[*i]))
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
	*i = *i + (ft_intlen(numb) - 1);
	return (1);
}

int				check_length(char find, t_arg *sarg)
{
	int		k = 0;

	if (ft_strlen(sarg->length) == 0)
		k = 0;
	if (ft_strlen(sarg->length) < 2 && ft_strlen(sarg->prec) == 0
	&& ft_strlen(sarg->spec) == 0 && ft_strchr(LENGTH, find))
	{
		if (((sarg->length[0] == 'h' || sarg->length[0] == 'l')
		&& sarg->length[0] == find) || sarg->length[0] == '\0')
		{
			sarg->length[k++] = find;
			sarg->length[k] = '\0';
			return (1);
		}
		return (error("Length error"));
	}
	return (0);
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

static void		convert_spec(char arg, t_arg *sarg)
{
	if (arg == 'c' || arg == 'C' || arg == 'd' || arg == 'i')
		sarg->type = ft_strdup("int");
	else if (arg == 'u' || arg == 'o' || arg == 'x' || arg == 'X')
		sarg->type = ft_strdup("unsigned int");
	else if (arg == 'U' || arg == 'O' || arg == 'D')
		sarg->type = ft_strdup("long int");
	else if (arg == 's' || arg == 'S')
		sarg->type = ft_strdup("const char*");
	else if (arg == 'p')
		sarg->type = ft_strdup("void*");
}

int				check_spec(char find, t_arg *sarg)
{
	if (ft_strlen(sarg->spec) == 0 && ft_strchr(SPEC, find))
	{
		sarg->spec[0] = find;
		convert_spec(find, sarg);
		return (1);
	}
	return (0);
}

int				checks(const char *format, int *i, t_arg *sarg)
{
	int		isave;

	isave = *i;
	if (check_flags(format, i, sarg))
	{
		*i = *i + 1;
		isave = *i;
	}
	else
		*i = isave;
	if (check_number(ft_strsub(format, *i, ft_strlen(format) - *i),
	sarg, i))
	{
		*i = *i + 1;
		isave = *i;
	}
	else
		*i = isave;
	if (check_length(format[*i], sarg))
	{
		*i = *i + 1;
		isave = *i;
	}
	else
		*i = isave;
	if (check_prec(format[*i], format[*i + 1], i, sarg))
	{
		*i = *i + 1;
		isave = *i;
	}
	else
		*i = isave;
	if (check_spec(format[*i], sarg))
		return (1);
	else
		return (error("Parameter problem"));
}
