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

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

/*
	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define FLAGS{#,0,-,+,' '}
# define SPECIFIER{s,S,p,d,D,i,o,O,u,U,x,X,c,C}
# define PRECISION{".0",".n",*} //rien est egalement possible
# define LENGTH{h,hh,l,ll,j,z}

int		ft_printf(const char *format, ...);
int		recovery_arg(const char *format);
void	display_percent(int n);
void	display(const char *format);
int		percent(const char *format, int *i);

#endif
