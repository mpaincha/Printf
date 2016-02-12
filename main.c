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

// DECIMALE
	ft_putstr("\nFT_PTF : ");
	ft_printf("d: %d , hd: %hd, hd: %hd, hhd: %hhd, ld: %ld, lld: %lld, jd: %jd, zd: %zd ", -10, 781, 'b', 4545454510, 10, 10, 10, 4545454510);
	ft_putstr("\nPRINTF : ");
	printf("d: %d , hd: %hd, hd: %hd, hhd: %hhd, ld: %ld, lld: %lld, jd: %jd, zd: %zd ", -10, 781, 'b', 4545454510, 10, 10, 10, 4545454510);

//OCTAL
	// ft_putstr("\nFT_PTF : ");
	// ft_printf("o: %o , ho: %ho, ho: %ho, hho: %hho, lo: %lo, llo: %llo, jo: %jo, zo: %zo ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);
	// ft_putstr("\nPRINTF : ");
	// printf("o: %o , ho: %ho, ho: %ho, hho: %hho, lo: %lo, llo: %llo, jo: %jo, zo: %zo ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);

//UNSIG
	// ft_putstr("\nFT_PTF : ");
	// ft_printf("u: %u , hu: %hu, hu: %hu, hhu: %hhu, lu: %lu, llu: %llu, ju: %ju, zu: %zu ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);
	// ft_putstr("\nPRINTF : ");
	// printf("u: %u , hu: %hu, hu: %hu, hhu: %hhu, lu: %lu, llu: %llu, ju: %ju, zu: %zu ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);

//HEXALOWER
	// ft_putstr("\nFT_PTF : ");
	// ft_printf("x: %x , hx: %hx, hx: %hx, hhx: %hhx, lx: %lx, llx: %llx, jx: %jx, zx: %zx ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);
	// ft_pxtstr("\nPRINTF : ");
	// printf("x: %x , hx: %hx, hx: %hx, hhx: %hhx, lx: %lx, llx: %llx, jx: %jx, zx: %zx ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);

//HEXAUPPER
	// ft_putstr("\nFT_PTF : ");
	// ft_printf("X: %X , hX: %hX, hX: %hX, hhX: %hhX, lX: %lX, llX: %llX, jX: %jX, zX: %zX ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);
	// ft_pXtstr("\nPRINTF : ");
	// printf("X: %X , hX: %hX, hX: %hX, hhX: %hhX, lX: %lX, llX: %llX, jX: %jX, zX: %zX ", 10, 781, 'b', 545454410, 10, 10, 10, 445578);

return (0);
}


// ne marche pas si nombre = 4545454510 pour mon printf f
