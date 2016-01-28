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

void	action(t_dbllist *lst_arg, t_dbllist *lst_str)
{
	t_elem			*tmpa;
	char			*str;

	tmpa = lst_arg->head;
	str = NULL;
	while (tmpa != NULL)
	{
		str = ft_strdup(ARG->arg);
		if (ARG->flags.diez != 0 || ARG->flags.zero != 0 || ARG->flags.minus != 0
		|| ARG->flags.plus != 0 || ARG->flags.space != 0)
			action_flags(tmpa, lst_str, str);
		if (ARG->length[0] != '\0')
			action_length(tmpa, lst_str, str);
		if (ARG->prec[0] != '\0')
			action_prec(tmpa, lst_str, str);
		action_spec(tmpa, lst_str, str);
		tmpa = tmpa->next;
	}
}

		// ft_putstr("\nstr :");
		// ft_putstr(str);
		// ft_putstr("\n");
