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
	int			i;
	static int	j = 0;

	i = 0;
	if (ft_strlen(((t_arg *)(tmp->content))->flags) == 0)
		j = 0;
	if (ft_strlen(((t_arg *)(tmp->content))->length) == 0 && ft_strlen(((t_arg *)(tmp->content))->prec) == 0
	&& ft_strlen(((t_arg *)(tmp->content))->spec) == 0 && ft_strchr(FLAGS, find))
	{
		while (((t_arg *)(tmp->content))->flags[i] != '\0' && ((t_arg *)(tmp->content))->flags[i] != find)
			i++;
		if (((t_arg *)(tmp->content))->flags[i] == find)
			return (1);
		((t_arg *)(tmp->content))->flags[j++] = find;
		((t_arg *)(tmp->content))->flags[j] = '\0';
		return (1);
	}
	return (0);
}

static int		check_length(char find, t_elem *tmp)
{
	static int	k = 0;

	if (ft_strlen(((t_arg *)(tmp->content))->length) == 0)
		k = 0;
	if (ft_strlen(((t_arg *)(tmp->content))->length) < 2 && ft_strlen(((t_arg *)(tmp->content))->prec) == 0
	&& ft_strlen(((t_arg *)(tmp->content))->spec) == 0 && ft_strchr(LENGTH, find))
	{
		if (((((t_arg *)(tmp->content))->length[0] == 'h' || ((t_arg *)(tmp->content))->length[0] == 'l')
		&& ((t_arg *)(tmp->content))->length[0] == find) || ((t_arg *)(tmp->content))->length[0] == '\0')
		{
			((t_arg *)(tmp->content))->length[k++] = find;
			((t_arg *)(tmp->content))->length[k] = '\0';
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
	if (ft_strlen(((t_arg *)(tmp->content))->prec) == 0 && ft_strlen(((t_arg *)(tmp->content))->spec) == 0
	&& ft_strchr(PREC, find))
	{
		((t_arg *)(tmp->content))->prec[0] = find;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static void		convert_spec(char arg, t_elem *tmp)
{
	if (arg == 'c' || arg == 'C' || arg == 'd' || arg == 'i')
		((t_arg *)(tmp->content))->type = ft_strdup("int");
	else if (arg == 'u' || arg == 'o' || arg == 'x' || arg == 'X')
		((t_arg *)(tmp->content))->type = ft_strdup("unsigned int");
	else if (arg == 'U' || arg == 'O' || arg == 'D')
		((t_arg *)(tmp->content))->type = ft_strdup("long int");
	else if (arg == 's' || arg == 'S')
		((t_arg *)(tmp->content))->type = ft_strdup("const char*");
	else if (arg == 'p')
		((t_arg *)(tmp->content))->type = ft_strdup("void*");
}

static int		check_spec(char find, t_elem *tmp)
{
	if (ft_strlen(((t_arg *)(tmp->content))->spec) == 0 && ft_strchr(SPEC, find))
	{
		((t_arg *)(tmp->content))->spec[0] = find;
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
	if (ft_strlen(((t_arg *)(tmp->content))->spec) != 1)
		return (error("Missing specifier"));
	tmp = tmp->next;
	if (format[*i] != '\0')
		display(format, lst_arg, tmp);
	return (1);
}
