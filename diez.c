/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diez.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:26:12 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/22 11:26:14 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez_o(char **str)
{
	char	*tmp;

	tmp = ft_strjoin("0", *str);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static void		replace_one_space(char **str, char *tmp)
{
	char	*tmp2;
	char	*bg;
	char	*ed;
	int		i;
	int		j;

	tmp2 = NULL;
	bg = NULL;
	ed = NULL;
	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(*str) + 1);
	while (!(ft_isdigit((*str)[i])))
		i++;
	bg = ft_strnew(i + 1);
	i = 0;
	while (!(ft_isdigit((*str)[i])))
	{
		bg[i] = (*str)[i];
		i++;
	}
	bg[i - 1] = '0';
	bg[i] = '\0';
	tmp = ft_strjoin(bg, "X");
	ft_strdel(&bg);
	ed = ft_strnew(ft_strlen(*str) - ft_strlen(bg) + 1);
	while (str[i] != '\0')
		ed[j++] = (*str)[i++];
	ed[j] = '\0';
	tmp2 = ft_strnew(ft_strlen(*str) + 1);
	tmp2 = ft_strjoin(tmp, ed);
	ft_strdel(str);
	ft_strdel(&bg);
	ft_strdel(&ed);
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp2);
}

static void		replace_two_space(char **str, char *tmp)
{
	char	*tmp2;
	char	*bg;
	char	*ed;
	int		i;
	int		j;

	tmp2 = NULL;
	bg = NULL;
	ed = NULL;
	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(*str));
	while (!(ft_isdigit((*str)[i])))
		i++;
	bg = ft_strnew(i + 1);
	i = 0;
	while (!(ft_isdigit((*str)[i])))
	{
		bg[i] = (*str)[i];
		i++;
	}
	bg[i - 2] = '0';
	bg[i - 1] =  'X';
	bg[i] = '\0';
	ft_strdel(&tmp);
	ed = ft_strnew(ft_strlen(*str) - ft_strlen(bg));
	while (str[i] != '\0')
		ed[j++] = (*str)[i++];
	ed[j] = '\0';
	tmp2 = ft_strnew(ft_strlen(*str));
	tmp2 = ft_strjoin(bg, ed);
	ft_strdel(str);
	ft_strdel(&bg);
	ft_strdel(&ed);
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp2);
}

void	diez_hexaupper_space(char **str, size_t len, size_t w)
{
	char	*tmp;

	tmp = NULL;
	if (w > len)
	{
		if (w - len == 1)
			replace_one_space(str, tmp);
		else
			replace_two_space(str, tmp);
	}
	else
	{
		tmp = ft_strjoin("0X", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	diez_hexaupper_zero(char **str, size_t len, size_t w)
{
	char	*tmp;

	tmp = NULL;
	if (w > len)
	{
		if (w - len == 1)
		{
			(*str)[0] = 'X';
			tmp = ft_strjoin("0", *str);
			ft_strdel(str);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
		{
			(*str)[0] = '0';
			(*str)[1] = 'X';
			ft_strdel(&tmp);
		}

	}
	else
	{
		tmp = ft_strjoin("0X", *str);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}
