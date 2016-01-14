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

# include "libftprintf/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
	% [drapeaux] [largeur] [.precision] [modificateur] type
*/

# define FLAGS "#0-+ "
# define LENGTH "hljz"
# define PREC "0n*" //il doit y avoir un point devant + rien est egalement possible
# define SPEC "sSpdDioOuUxXcC"

typedef struct		s_arg
{
	char			*flags;
	char			length;
	char			prec;
	char			spec;

}					t_arg;

int		ft_printf(const char *format, ...);
int		save_arg(char *arg);
void	display_percent(int n);
void	display(const char *format);
int		percent(const char *format, int *i);

#endif
