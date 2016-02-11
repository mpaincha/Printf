/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:13:32 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:13:34 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// ft_printf("%s%S%p%d%D%i%o%O%u%U%x%X%c%C", "s", "S", "p", "d", "D", "i", "o", "O", "u", "U", "x", "X", "c", "C");
	// ft_printf("d: %d\n i : %i\n ld : %ld\n D :%D\n", 10, 10, 10, 10);
	ft_putstr("======   FT_PRINTF   ======\n\n");
	ft_printf("d: %d\n", 10);
	ft_putstr("======   PRINTF   ======\n");
	printf("d: %d\n", 10);
	ft_putstr("== == == == == == == == ==\n");
	ft_putstr("======   FT_PRINTF   ======\n\n");
	ft_printf("hd: %hd\n", 781);
	ft_putstr("======   PRINTF   ======\n");
	printf("hd: %hd\n", 781);
	ft_putstr("== == == == == == == == ==\n");
	ft_putstr("======   FT_PRINTF   ======\n\n");
	ft_printf("hhd: %hhd\n", 'b');
	ft_putstr("======   PRINTF   ======\n");
	printf("hhd: %hhd\n", 'b');
	ft_putstr("== == == == == == == == ==\n");
	// ft_putstr("======   FT_PRINTF   ======\n\n");
	// ft_printf("ld: %ld\n", 10);
	// ft_putstr("======   PRINTF   ======\n");
	// printf("lld: %lld\n", 10);
	// ft_putstr("== == == == == == == == ==\n");
	// ft_putstr("======   FT_PRINTF   ======\n\n");
	// ft_printf("jd: %jd\n", 10);
	// ft_putstr("======   PRINTF   ======\n");
	// printf("jd: %jd\n", 10);
	// ft_putstr("== == == == == == == == ==\n");
	// ft_putstr("======   FT_PRINTF   ======\n\n");
	// ft_printf("zd: %zd\n", 10);
	// ft_putstr("======   PRINTF   ======\n");
	// printf("zd: %zd\n", 10);
	// ft_putstr("== == == == == == == == ==\n");
	// ft_putstr("======   FT_PRINTF   ======\n\n");
	// ft_printf("D: %D\n", 4545454510);
	// ft_putstr("======   PRINTF   ======\n");
	// printf("D: %D\n", 4545454510);
	// ft_putstr("== == == == == == == == ==\n");
return (0);
}
