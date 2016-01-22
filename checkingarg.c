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

static int		check_flags(char find, t_elem *tmp)
{
	int			k;
	static int	j = 0;

	k = 0;
	if (ft_strlen(ARG->flags) == 0)
		j = 0;
	if (ft_strlen(ARG->length) == 0 && ft_strlen(ARG->prec) == 0
	&& ft_strlen(ARG->spec) == 0 && ft_strchr(FLAGS, find))
	{
		while (ARG->flags[k] != '\0' && ARG->flags[k] != find)
			k++;
		if (ARG->flags[k] == find)
			return (1);
		ARG->flags[k++] = find;
		ARG->flags[k] = '\0';
		return (1);
	}
	return (0);
}

static int		check_length(char find, t_elem *tmp)
{
	static int	k = 0;

	if (ft_strlen(ARG->length) == 0)
		k = 0;
	if (ft_strlen(ARG->length) < 2 && ft_strlen(ARG->prec) == 0
	&& ft_strlen(ARG->spec) == 0 && ft_strchr(LENGTH, find))
	{
		if (((ARG->length[0] == 'h' || ARG->length[0] == 'l')
		&& ARG->length[0] == find) || ARG->length[0] == '\0')
		{
			ARG->length[k++] = find;
			ARG->length[k] = '\0';
			return (1);
		}
		return (error("Length error"));
	}
	return (0);
}

static int		check_prec(char point, char find, int *i,
				t_elem *tmp)
{
	if (point != '.')
		return (0);
	if (ft_strlen(ARG->prec) == 0 && ft_strlen(ARG->spec) == 0
	&& ft_strchr(PREC, find))
	{
		ARG->prec[0] = find;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static void		convert_spec(char arg, t_elem *tmp)
{
	if (arg == 'c' || arg == 'C' || arg == 'd' || arg == 'i')
		ARG->type = ft_strdup("int");
	else if (arg == 'u' || arg == 'o' || arg == 'x' || arg == 'X')
		ARG->type = ft_strdup("unsigned int");
	else if (arg == 'U' || arg == 'O' || arg == 'D')
		ARG->type = ft_strdup("long int");
	else if (arg == 's' || arg == 'S')
		ARG->type = ft_strdup("const char*");
	else if (arg == 'p')
		ARG->type = ft_strdup("void*");
}

static int		check_spec(char find, t_elem *tmp)
{
	if (ft_strlen(ARG->spec) == 0 && ft_strchr(SPEC, find))
	{
		ARG->spec[0] = find;
		convert_spec(find, tmp);
		return (1);
	}
	return (0);
}

void	ini_sarg(t_arg *sarg)
{
	sarg->arg = NULL;
	sarg->flags = ft_strnew(sizeof(char) * 5);
	sarg->length = ft_strnew(sizeof(char) * 2);
	sarg->prec = ft_strnew(sizeof(char) * 1);
	sarg->spec = ft_strnew(sizeof(char) * 1);
	sarg->type = NULL;
}

int				split_arg(const char *format, t_dbllist *lst_arg, int *i,
				t_elem *tmp)
{
	while (format[*i] != '\0')
	{
		if (check_flags(format[*i], tmp))
			*i = *i + 1;
		else if (check_length(format[*i], tmp))
			*i = *i + 1;
		else if (check_prec(format[*i], format[*i + 1], i, tmp))
			*i = *i + 1;
		else if (check_spec(format[*i], tmp))
			break ;
		else
			return (error("Parameter problem"));
	}
	*i = *i + 1;
	if (ft_strlen(ARG->spec) != 1)
		return (error("Missing specifier"));
	tmp = tmp->next;
	if (format[*i] != '\0')
		display(format, lst_arg, tmp);
	return (1);
}
