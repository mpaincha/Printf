/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:38:26 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 13:38:28 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Fonctions debug
*/

void	ft_putlst(t_dbllist	*list)
{
	t_elem	*tmp;

	tmp = list->head;
	ft_putstr("AFFICHAGE LISTE: \n");
	while (tmp != NULL)
	{
		ft_putstr("\nMAILLON : \n");
		ft_putstr("flags : ");
		ft_putstr(((t_arg *)(tmp->content))->flags);
		ft_putstr("\nlength : ");
		ft_putstr(((t_arg *)(tmp->content))->length);
		ft_putstr("\nprec : ");
		ft_putstr(((t_arg *)(tmp->content))->prec);
		ft_putstr("\nspec : ");
		ft_putstr(((t_arg *)(tmp->content))->spec);
		ft_putstr("\ntype : ");
		ft_putstr(((t_arg *)(tmp->content))->type);
		tmp = tmp->next;
	}
}

/*
	Fin fonctions debug
*/

// static int			save_arg(char *arg, t_dbllist *lst_arg)
// {

// 	t_arg		sarg;

// 	ini_sarg(&sarg);
// 	if (!(split_arg(arg, sarg)))
// 		return (0);
// 	ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
// 	ft_putlst(lst_arg);
// 	return (1);
// }

// static int			arglen(const char *format, int i)
// {
// 	size_t	len;

// 	len = 0;
// 	while (format[i] != ' ' && format[i] != '\0')
// 	{
// 		i++;
// 		len++;
// 	}
// 	return (len);
// }

// int			recovery_arg(const char *format, int *i, t_dbllist *lst_arg)
// {
// 	char	*arg;
// 	int		j;

// 	j = 0;
// 	*i = *i + 1;
// 	if (format[*i])
// 	{
// 		arg = ft_strnew(arglen(format, *i));
// 		while (format[*i] != ' ' && format[*i] != '\0')
// 		{
// 			arg[j] = format[*i];
// 			j++;
// 			*i = *i + 1;
// 		}
// 		arg[j] = '\0';
// 		if (!(save_arg(arg, lst_arg)))
// 			return (0);
// 		printf("\nRappel Argument : %s\n",arg);
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

// static	int		countarg(const char *format, t_dbllist **lst_arg)
// {
// 	int		i;
// 	int		arg;

// 	i = 0;
// 	arg = 0;
// 	while (format[i] != '\0')
// 	{
// 		if (format[i] == '%')
// 		{
// 			arg++;
// 			if (percent(format, &i) == 0)
// 				arg--;
// 			else
// 				recovery_arg(format, &i, lst_arg);
// 		}
// 		i++;
// 	}
// 	return (arg);
// }
