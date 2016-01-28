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
	if (ac == 8)
	{
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7]);
		printf("%#3o\n", 125);
		return (1);
	}
	else if (ac == 5)
	{
		ft_printf(av[1], av[2], av[3], av[4]);
		printf("%#3o\n", 125);
		return (1);
	}
	else if (ac == 4)
	{
		ft_printf(av[1], av[2], av[3]);
		printf("%#3o\n", 125);
		return (1);
	}
	else if (ac == 3)
	{
		ft_printf(av[1], av[2]);
		printf("%#3o\n", 125);
		return (1);
	}
	else if (ac == 2)
	{
		ft_printf(av[1]);
		return (1);
	}
	else
		return (0);
}
