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

int		main(int ac, char **av)
{
	if (ac == 5)
	{
		ft_printf(av[1], av[2], av[3], av[4]);
		// printf("\n\nTest PRINTF\n");
		// printf("bonjour \n", 42);
		//printf("bonjour %d%d%d\n", 42, 1, 12);

		return (1);
	}
	else if (ac == 2)
	{
		ft_printf(av[1]);
		// printf("\n\nTest PRINTF\n");
		// printf("bonjour \n", 42);
		//printf("bonjour %d%d%d\n", 42, 1, 12);

		return (1);
	}
	else
		return (0);
}