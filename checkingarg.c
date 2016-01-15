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
	static int	k = 0; //ne marche pas pour les prochains %% rencontre
	//car il faudrait remettre la variable a 0 pour ca

	if (ft_strlen(sarg.length) == 0)
		k = 0;
	if (ft_strlen(sarg.length) < 2 && ft_strlen(sarg.prec) == 0
	&& ft_strlen(sarg.spec) == 0 && ft_strchr(LENGTH, find))
	{
		if (((sarg.length[0] == 'h' || sarg.length[0] == 'l')
		&& sarg.length[0] == find) || sarg.length[0] == '\0')
		{
			sarg.length[k++] = find;
			sarg.length[k] = '\0';
			return (1);
		}
		return (error("Length error"));
	}
	return (0);
}

static int		check_flags(t_arg sarg, char find)
{
	int			i;
	static int	j = 0; //ne marche pas pour les prochains %% rencontre
	//car il faudrait remettre la variable a 0 pour ca

	i = 0;
	if (ft_strlen(sarg.flags) == 0)
		j = 0;
	if (ft_strlen(sarg.length) == 0 && ft_strlen(sarg.prec) == 0
	&& ft_strlen(sarg.spec) == 0 && ft_strchr(FLAGS, find))
	{
		while (sarg.flags[i] != '\0' && sarg.flags[i] != find)
			i++;
		if (sarg.flags[i] == find)
			return (error("Flags error"));
		sarg.flags[j++] = find;
		sarg.flags[j] = '\0';
		return (1);
	}
	return (0);
}

int				split_arg(char *arg, t_arg sarg)
{
	int			i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (check_flags(sarg, arg[i]))
			continue ;
		else if (check_length(sarg, arg[i]))
			continue ;
		else if (arg[i] == '.' && ft_strlen(sarg.prec) == 0 &&
		ft_strlen(sarg.spec) == 0 && ft_strchr(PREC, arg[i + 1]))
		{
			sarg.prec[0] = arg[i + 1];
			i++;
		}
		else if (ft_strlen(sarg.spec) == 0 && ft_strchr(SPEC, arg[i]))
			sarg.spec[0] = arg[i];
		else
			return (error("Parameter probleme"));
	}
	if (sarg.spec == 0)
		return (error("Missing specifier"));
	printf("\nsarg.flags  : %s\n", sarg.flags);
	printf("sarg.length  :%s\n", sarg.length);
	printf("sarg.prec :%s\n", sarg.prec);
	printf("sarg.spec :%s\n", sarg.spec);
	return (1);
}

