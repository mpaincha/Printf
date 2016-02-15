/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:59:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/15 10:59:10 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_mask(char *mask, wchar_t c)
{
	while ()
}

void	mask(wchar_t c)
{
	if (c <= 127)
		//classique
	else if (c <= 2047)
		fill_mask(MASKA, c);
	else if (c <= 65535)
		fill_mask(MASKB, c);
	else
		fill_mask(MASKC, c);
}

char	*ft_wchar(t_elem *tmpa)
{
	char	*str;
	char	*dec; //debug

	ft_putstr("\n\nFT WCHAR : "); //debug
	dec = ft_strdup(ft_itoabase_imax((wchar_t)ARG->arg, 10));
	ft_putstr("\n\nen dec : "); //debug
	ft_putstr(dec); //debug
	ft_putstr("\n\n"); //debug
	str = ft_strdup(ft_itoabase_imax((wchar_t)ARG->arg, 2));
	mask((wchar_t)ARG->arg);
	ft_putstr("\n\nen binaire : ");
	ft_putstr(str);
	ft_putstr("\n\n");
	return (str);
}

// 0xxxxxxx
// 110xxxxx 10xxxxxx
// 1110xxxx 10xxxxxx 10xxxxxx
// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
