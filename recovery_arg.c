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

static	void		ini_sarg(t_arg *sarg)
{
	sarg->flags = ft_strnew(5);
	sarg->length = 0;
	sarg->prec = 0;
	sarg->spec = 0;
}

static	int			split_arg(char *arg)
{
	t_arg	sarg;
	int		i;
	int		j;
	(void) arg;

	i = 0;
	j = 0;
	ini_sarg(&sarg);
	while (arg[i] != '\0')
	{
		if (sarg.length == 0 && sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(FLAGS, arg[i])) //verifier qu'on q pqs deux foi la mem lettre
			sarg.flags[j++] = arg[i];
		else if (sarg.length == 0 && sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(LENGTH, arg[i]))
			sarg.length = arg[i];
		else if (sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(PREC, arg[i]))
			sarg.prec = arg[i];
		else if (sarg.spec == 0 && ft_strchr(SPEC, arg[i]))
			sarg.spec = arg[i];
		else
			return (-1);
		i++;
	}
	printf("\nsarg.flags  : %s\n", sarg.flags);
	printf("sarg.length  :%c\n", sarg.length);
	printf("sarg.prec :%c\n", sarg.prec);
	printf("sarg.spec :%c\n", sarg.spec);
	return (1);
}

int					save_arg(char *arg)
{
	t_dbllist	*lst_arg;

	lst_arg = ft_lstdblnew();
	split_arg(arg);
	return (1);
}

static int			arglen(const char *format, int i)
{
	size_t	len;

	len = 0;
	while (format[i] != ' ' && format[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int			recovery_arg(const char *format, int *i)
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
		save_arg(arg);
		printf("Argument : %s\n",arg);
		return (1);
	}
	else
		return (-1);
}

int					percent(const char *format, int *i)
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
		display_percent(percent/2);
		if (percent % 2 == 0)
			return (0);
	}
	if (!recovery_arg(format, i))
		return (-1);
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
// 				recovery_arg(format, &i, lst_arg);
// 		}
// 		i++;
// 	}
// 	return (arg);
// }

