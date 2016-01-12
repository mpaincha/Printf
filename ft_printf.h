/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:14:43 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:14:57 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft.h"
# include <stdarg.h>
#include <stdio.h>

/*
	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define SPECIFIER {s,S,p,d,D,i,o,O,u,U,x,X,c,C}
# define FLAGS {#,0,-,+,' '}
# define PRECISION {.0,.n,*} //rien est egalement possible


int		ft_printf(const char *format, ...);

#endif
