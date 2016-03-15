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

#include "../includes/libft.h"

void	ft_lstdbldel(t_dbllist **list)
{
	t_elem	*tmp;

	tmp = (*list)->head;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = tmp->next;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
}
