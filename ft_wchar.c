/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:59:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/15 10:59:10 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_findstr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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

char	*mask(t_elem *tmpa, wchar_t c)
{
	char	*nb;

	nb = ft_strdup(ft_itoabase_imax((wchar_t)ARG->arg, 2));
	if (c <= 127)
		return (fill_mask((wchar_t)ARG->arg));
	else if (c <= 2047)
		return (fill_maska((wchar_t)ARG->arg));
	else if (c <= 65535)
		return (fill_maskb((wchar_t)ARG->arg));
	else
		return (fill_maskc((wchar_t)ARG->arg));
}

char	*ft_wchar(t_elem *tmpa)
{
	char	*nb;
	char	*dec; //debug

	ft_putstr("\n\nFT WCHAR : "); //debug
	dec = ft_strdup(ft_itoabase_imax((wchar_t)ARG->arg, 10));
	ft_putstr("\n\nen dec : "); //debug
	ft_putstr(dec); //debug
	ft_putstr("\n\n"); //debug
	nb = ft_strdup(mask(tmpa, (wchar_t)ARG->arg));
	// ft_putstr("\n\nen binaire : ");
	// ft_putstr(str);
	// ft_putstr("\n\n");
	return (nb);
}

// 0xxxxxxx
// 110xxxxx 10xxxxxx
// 1110xxxx 10xxxxxx 10xxxxxx
// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
