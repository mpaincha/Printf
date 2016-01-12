/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:12:51 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:12:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_whicharg(const char *format, int i)
// {
// 	char	*spec;
// 	int		j;

// 	spec = 0;
// 	j = 0;
// 	if (format[i])
// 	{
// 		while (format[i] != ' ')
// 			spec[j++] = format[i++];
// 	}
// 	else
// 		return (-1);
// }

int		ft_percent(const char *format, int *i)
{
	int		percent;

	percent = 1;
	while (format[*i + 1] == '%')
	{
		percent++;
		*i = *i + 1;
	}
	if (percent > 1)
	{
		if (percent % 2 == 0)
			return (0);
	}
	return (1);
}

int		ft_countarg(const char *format)
{
	int		i;
	int		arg;

	i = 0;
	arg = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			arg++;
			if (ft_percent(format, &i) == 0)
				arg--;
		}
		i++;
	}
	return (arg);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	va_start(ap, format);

	printf("Il y a %d signes %%\n", ft_countarg(format));
	//va_arg(ap, ); //en deuxieme, il faut le type de parametre  qu'on recupere,
	//le type du ap en cours
	va_end(ap); //il faut terminer par ca obligatoirement
	return (1);
}

// #include <stdio.h>
// int		multiplication(int *resultat, ...)
// {
// 	int parametre = 1; // Valeur du paramètre actuel
// 	*resultat = 1;
// 	va_list ap;

// 	va_start(ap, resultat);
// 	while (parametre)
// 	{ // On fait ce qui suit...
// 		*resultat *= parametre; // on multiplie le produit par le paramètre actuel
// 		parametre = va_arg(ap, int); // on obtient le paramètre actuel
// 	}
// 	va_end(ap);
// 	return (*resultat);
// }

// int		main(void)
// {
// 	int		resultat;
// 	int		res;
// 	int		c1;
// 	int		c2;
// 	int		c3;

// 	resultat = 0;
// 	c1 = 1;
// 	c2 = 3;
// 	c3 = 5;
// 	res = multiplication(&resultat, c1, c2, c3);
// 	printf("resultat de la multiplication : %d", res);
// }
