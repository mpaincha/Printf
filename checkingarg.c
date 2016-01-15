/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 18:40:33 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_length(t_arg sarg, char find)
{
	if (((sarg.length[0] == 'h' || sarg.length[0] == 'l')
	&& sarg.length[0] == find) || sarg.length[0] == '\0')
		return (1);
	return (-1);
}

static int		check_flags(t_arg sarg, char find)
{
	int		i;

	i = 0;
	while (sarg.flags[i] != '\0' && sarg.flags[i] != find)
		i++;
	if (sarg.flags[i] == find)
		return (-1);
	return (1);
}

int				split_arg(char *arg, t_arg sarg)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (arg[i] != '\0')
	{
	//	if (check_flags() == 1);


		if (ft_strlen(sarg.length) == 0 && sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(FLAGS, arg[i]))
		{
			if (check_flags(sarg, arg[i]) == 1)
				sarg.flags[j++] = arg[i];
			else
				return (-1);
		}
		else if (ft_strlen(sarg.length) < 2 && sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(LENGTH, arg[i]))
		{
			if (check_length(sarg, arg[i]) == 1)
				sarg.length[k++] = arg[i];
			else
				return (-1);

		}
		else if (sarg.prec == 0 && sarg.spec == 0
		&& ft_strchr(PREC, arg[i]))
			sarg.prec = arg[i];
		else if (sarg.spec == 0 && ft_strchr(SPEC, arg[i]))
			sarg.spec = arg[i];
		else
			return (-1);
		i++;
	}
	if (sarg.spec == 0)
		return (-1);
	printf("\nsarg.flags  : %s\n", sarg.flags);
	printf("sarg.length  :%s\n", sarg.length);
	printf("sarg.prec :%c\n", sarg.prec);
	printf("sarg.spec :%c\n", sarg.spec);
	return (1);
}
