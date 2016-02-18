/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:06:14 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/20 16:12:56 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdbldel(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = NULL;
	while (list->head != NULL)
	{
		tmp = list->head->next;
		free(list->head->content);
		list->head->content = NULL;
		free(list->head);
		list->head = tmp;
	}
	list->tail = NULL;
	list->head = NULL;
}

// void	ft_lstdbldel(t_dbllist *list)
// {
// 	t_elem	*tmp;

// 	tmp = NULL;
// 	while (list->head != NULL)
// 	{
// 		tmp = list->head->next;
// 		free(list->head->content);
// 		list->head->content = NULL;
// 		free(list->head);
// 		list->head = tmp;
// 	}
// 	list->tail = NULL;
// 	list->head = NULL;
// }

// void dlist_delete(Dlist **p_list)
// {
//     if (*p_list != NULL)
//     {
//         struct node *p_temp = (*p_list)->p_head;
//         while (p_temp != NULL)
//         {
//             struct node *p_del = p_temp;
//             p_temp = p_temp->p_next;
//             free(p_del);
//         }
//         free(*p_list), *p_list = NULL;
//     }
// }


// void	ft_lstdbldel(t_dbllist **list)
// {
// 	t_elem	*tmp;
// 	t_elem	*del;

// 	if (*list != NULL)
// 	{
// 		tmp = (*list)->head;
// 		while (tmp != NULL)
// 		{
// 			del = tmp;
// 			tmp = tmp->next;
// 			free(del);
// 		}
// 		free(*list);
// 		*list = NULL;
// 	}
// }
