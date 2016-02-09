/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:12:41 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/09 17:12:43 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_c(t_elem *tmpa, void *arg)
{
	if (SMOD.l == 0)
		return (ft_itoabase_imax((int)arg, 10));
	// A VOIR apres c avec l qui correspond 0 C



	if (ARG->spec[0] == 'u')
		return (ft_itoabase_imax((unsigned int)arg, 10));
	if (ARG->spec[0] == 'U' || ARG->spec[0] == 'D')
		return (ft_itoabase_imax((long int)arg, 10));
	if (ARG->spec[0] == 'd' || ARG->spec[0] == 'i')
		return (ft_itoabase_imax((int)arg, 10));
	if (ARG->spec[0] == 'o')
		return (ft_itoabase_imax((unsigned int)arg, 8));
	if (ARG->spec[0] == 'O' )
		return (ft_itoabase_imax((long int)arg, 8));
	if (ARG->spec[0] == 'X')
		return (ft_itoabase_imax((unsigned int)arg, 16));
	if (ARG->spec[0] == 'x')
		return (ft_itoabase_imax_x((unsigned int)arg, 16));
	if (ARG->spec[0] == 'p')
		return (ft_itoabase_imax((int)arg, 16));
	if (ARG->spec[0] == 's' || ARG->spec[0] == 'S')
		return ((char *)arg);
}
