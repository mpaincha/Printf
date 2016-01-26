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

int				check_flags(char find, t_elem *tmp)
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

int				check_number(char *str, t_elem *tmp, int	*i)
{
	int		numb;

	numb = 0;
	if ((numb = ft_atoi(str)))
		ARG->numb = numb;
	else
		return (0);
	*i = *i + (ft_intlen(numb) - 1);
	return (1);
}

int				check_length(char find, t_elem *tmp)
{
	int		k = 0;

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

int				check_prec(char point, char find, int *i,
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

int				check_spec(char find, t_elem *tmp)
{
	if (ft_strlen(ARG->spec) == 0 && ft_strchr(SPEC, find))
	{
		ARG->spec[0] = find;
		convert_spec(find, tmp);
		return (1);
	}
	return (0);
}
