/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:22:01 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 18:22:02 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlststr(t_dbllist	*list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
}

void	display_percent(int nb, t_dbllist *lst_str)
{
	char	*str;
	int		i;

	str = ft_strnew(nb);
	i = 0;
	if (nb >= 1)
	{
		while (i < nb)
		{
			str[i] = '%';
			i++;
		}
		str[i] = '\0';
		ft_lstdbladd(lst_str, str, (sizeof(char) * nb));
	}
}

int		stock_str(const char *format, int i, t_dbllist *lst_str)
{
	char 	*str;
	int		start;

	str = NULL;
	start = i;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	str = ft_strsub(format, start, (i - start));
	ft_lstdbladd(lst_str, str, (sizeof(char) * ft_strlen(str)));
	return (i - 1);
}

static	t_elem	*find_pos(char *spec, t_dbllist *lst_str)
{
	int			found;
	t_elem		*tmps;

	tmps = lst_str->head;
	found = 0;
	while (tmps != NULL && !found)
	{
		if (ft_strequ(tmps->content, spec))
		{
			found = 1;
			break ;
		}
		else
			tmps = tmps->next;
	}
	if (found == 0)
		tmps = NULL;
	return (tmps);
}

void	transformation(t_dbllist *lst_arg, t_dbllist *lst_str)
{
	t_elem		*tmpa;
	char		*str;
	t_action	ft_action[] = {ft_string, ft_ptr, ft_dec, ft_octal, ft_unsig,
				ft_hexalower, ft_hexaupper, ft_char};
	t_action	actions;
	t_elem		*tmps;

	tmpa = lst_arg->head;
	tmps = lst_str->head;
	str = NULL;
	while (tmpa != NULL)
	{
		ft_putstr("\nboucle transfromation \n");
		actions = ft_action[ARG->action];
		ft_putstr("actions");
		str = actions(tmpa, ARG->arg);
		tmps = find_pos(ARG->spec, lst_str);
		tmps->content = ft_strdup(str);
		tmpa = tmpa->next;
	}
}
