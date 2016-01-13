/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:38:26 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 13:38:28 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		arglen(const char *format, int i)
{
	size_t	len;

	len = 0;
	while (format[i] != ' ' && format[i] != '\0')
	{
		i++;
		len++;
	}
	printf("%zu\n", len);
	return (len);
}

static int		whicharg(const char *format, int *i)
{
	char	*arg;
	int		j;

	j = 0;
	*i = *i + 1;
	if (format[*i])
	{
		arg = ft_strnew(arglen(format, *i));
		while (format[*i] != ' ' && format[*i] != '\0')
		{
			arg[j] = format[*i];
			j++;
			*i = *i + 1;
		}
		arg[j] = '\0';
		printf("Argument : %s\n",arg);
		return (1);
	}
	else
		return (-1);
}

int		percent(const char *format, int *i)
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
		{
			display_percent(percent/2);
			return (0);
		}
	}
	whicharg(format, i);
	return (1);
}

// static	int		countarg(const char *format, t_dbllist **lst_arg)
// {
// 	int		i;
// 	int		arg;

// 	i = 0;
// 	arg = 0;
// 	while (format[i] != '\0')
// 	{
// 		if (format[i] == '%')
// 		{
// 			arg++;
// 			if (percent(format, &i) == 0)
// 				arg--;
// 			else
// 				whicharg(format, &i, lst_arg);
// 		}
// 		i++;
// 	}
// 	return (arg);
// }

// int		recovery_arg(const char *format)
// {
// 	t_dbllist	*lst_arg;
// 	size_t		nb_arg;

// 	lst_arg = ft_lstdblnew();
// 	nb_arg = countarg(format, &lst_arg);
// 	return (1);
// }
