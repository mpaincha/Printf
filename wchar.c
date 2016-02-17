/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:31:57 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/17 16:31:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_mask(wchar_t nb)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = nb;
	str[1] = '\0';
	return (str);
}

char	*fill_maska(wchar_t nb)
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		new_nb;
	char				*str;

	a = nb & 0x3F;
	nb = nb << 2;
	b = nb & 0x1F00;
	new_nb = a | b;
	new_nb = new_nb | 0xC080;
	str = ft_strnew(2);
	str[0] = new_nb >> 8;
	str[1] = new_nb;
	str[2] = '\0';
	return (str);
}

char	*fill_maskb(wchar_t nb)
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		new_nb;
	char				*str;

	a = nb & 0x3F;
	nb = nb << 2;
	b = nb & 0x3F00;
	nb = nb << 2;
	c = nb & 0xF0000;
	new_nb = a | b | c | 0xE08080;
	str = ft_strnew(3);
	str[0] = new_nb >> 16;
	str[1] = new_nb >> 8;
	str[2] = new_nb;
	str[3] = '\0';
	return (str);
}

char	*fill_maskc(wchar_t nb)
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		new_nb;
	char				*str;

	a = nb & 0x3F;
	nb = nb << 2;
	b = nb & 0x3F00;
	nb = nb << 2;
	c = nb & 0x3F0000;
	nb = nb << 2;
	d = nb & 0x70000000;
	new_nb = a | b | c | d | 0xF0808080;
	str = ft_strnew(4);
	str[0] = new_nb >> 24;
	str[1] = new_nb >> 16;
	str[2] = new_nb >> 8;
	str[3] = new_nb;
	str[4] = '\0';
	return (str);
}

char	*mask(wchar_t c)
{
	if (c <= 127)
		return (fill_mask(c));
	else if (c <= 2047)
		return (fill_maska(c));
	else if (c <= 65535)
		return (fill_maskb(c));
	else
		return (fill_maskc(c));
}

char	*ft_wchar_str(t_elem *tmpa)
{
	char		*str;
	wchar_t		*arg;
	int			i;

	i = 0;
	arg = (wchar_t *)ARG->arg;
	str = ft_strnew(0);
	str[0] = '\0';
	while (arg[i])
	{
		str = ft_strjoin(str, mask(arg[i]));
		i++;
	}
	return (str);
}
