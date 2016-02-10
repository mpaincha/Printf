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

int		stock_str(const char *format, int	i, t_dbllist *lst_str)
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

void	transformation(t_dbllist *lst_arg, t_dbllist *lst_str)
{
	t_elem		*tmpa;
	char		*str;
	t_action	fct_action[] = {ft_string, ft_ptr, ft_dec, ft_octal, ft_unsig,
				ft_hexalower, ft_hexaupper, ft_char};
	t_action	actions;

	tmpa = lst_arg->head;
	str = NULL;
	while (tmpa != NULL)
	{
		actions = fct_action[ARG->action];
		str = actions(tmpa, ARG->arg);
		ft_lstdbladd(lst_str, str, (sizeof(char) * ft_strlen(str)));
		// if (ARG->flags.diez != 0 || ARG->flags.zero != 0 || ARG->flags.minus != 0
		// || ARG->flags.plus != 0 || ARG->flags.space != 0)
		// 	action_flags(tmpa, lst_str, str);
		// if (ARG->mod.h != 0 || ARG->mod.l != 0 || ARG->mod.j != 0
		// || ARG->mod.z != 0)
		// 	action_mod(tmpa, lst_str, str);
		// if (ARG->prec.pt != 0)
		// 	action_prec(tmpa, lst_str, str);
		// action_spec(tmpa, lst_str, str);
		tmpa = tmpa->next;
	}
}
