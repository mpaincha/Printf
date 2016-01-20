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

static int		check_length(t_arg *sarg, char find)
{
	static int	k = 0;

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

static int		check_flags(t_arg *sarg, char find)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (ft_strlen(sarg->flags) == 0)
		j = 0;
	if (ft_strlen(sarg->length) == 0 && ft_strlen(sarg->prec) == 0
	&& ft_strlen(sarg->spec) == 0 && ft_strchr(FLAGS, find))
	{
		while (sarg->flags[i] != '\0' && sarg->flags[i] != find)
			i++;
		if (sarg->flags[i] == find)
			return (error("Flags error"));
		sarg->flags[j++] = find;
		sarg->flags[j] = '\0';
		return (1);
	}
	return (0);
}

static int		check_prec(t_arg *sarg, char point, char find, int *i)
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

static int		check_spec(t_arg *sarg, char find)
{

	if (ft_strlen(sarg->spec) == 0 && ft_strchr(SPEC, find))
	{
		sarg->spec[0] = find;
		convert_spec(find, sarg);
		return (1);
	}
	return (0);
}

static	void	ini_sarg(t_arg *sarg)
{
	sarg->flags = ft_strnew(sizeof(char) * 5);
	sarg->length = ft_strnew(sizeof(char) * 2);
	sarg->prec = ft_strnew(sizeof(char) * 1);
	sarg->spec = ft_strnew(sizeof(char) * 1);
	sarg->type = NULL;
}

int				split_arg(const char *format, t_dbllist *lst_arg, int *i)
{
	t_arg	sarg;

	ini_sarg(&sarg);
	while (format[*i] != '\0')
	{
		if (check_flags(&sarg, format[*i]))
			*i = *i + 1;
		else if (check_length(&sarg, format[*i]))
			*i = *i + 1;
		else if (check_prec(&sarg, format[*i], format[*i + 1], i))
			*i = *i + 1;
		else if (check_spec(&sarg, format[*i]))
			break ;
		else
			return (error("Parameter problem"));
	}
	*i = *i + 1;
	if (ft_strlen(sarg.spec) != 1)
	{
		clean_lst(lst_arg);
		return (error("Missing specifier"));
	}
	ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
	if (format[*i] != '\0')
		display(format, lst_arg);
	return (1);
}
