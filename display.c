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

// void	action(t_dbllist *lst_arg, t_dbllist *lst_str)
// {
// 	t_elem			*tmpA;
// 	t_elem			*tmpS;

// 	tmpA = lst_arg->head;
// 	tmpS = lst_str->head;
// 	if (ft_strlen(ARG->flags) != 0)
// 		action_flags();
// 	if (ARG->length != '\0')
// 		action_length();
// 	if (ARG->prec != '\0')
// 		action_prec();
// 	action_spec();
// }
