/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:17:37 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 10:17:45 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static uintmax_t	ft_length_o(t_list *l, va_list ap)
{
	uintmax_t nbr;

	nbr = va_arg(ap, uintmax_t);
	if (ft_strequ(l->length, "hh"))
		nbr = (unsigned char)nbr;
	else if (ft_strequ(l->length, "h"))
		nbr = (unsigned short int)nbr;
	else if (ft_strequ(l->length, "l") || l->spec == 'O' || l->spec == 'U')
		nbr = (unsigned long int)nbr;
	else if (ft_strequ(l->length, "ll"))
		nbr = (unsigned long long int)nbr;
	else if (ft_strequ(l->length, "j"))
		nbr = (uintmax_t)nbr;
	else if (ft_strequ(l->length, "z"))
		nbr = (size_t)nbr;
	else if (ft_strequ(l->length, "t"))
		nbr = (ptrdiff_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

static char			*ft_flags_o(t_list *l, uintmax_t nbr)
{
	char	*s;

	s = NULL;
	if ((l->spec == 'o' || l->spec == 'O')
			&& nbr != 0 && ft_strchr(l->flags, '#') != 0)
		s = "0";
	else if (l->spec == 'x' && nbr != 0 && ft_strchr(l->flags, '#') != 0)
		s = "0x";
	else if (l->spec == 'X' && nbr != 0 && ft_strchr(l->flags, '#') != 0)
		s = "0X";
	return (s);
}

int					ft_conv_octal(t_list *l, va_list ap, int i)
{
	uintmax_t	nbr;
	char		*str;
	char		*tmp;
	char		*s;

	nbr = ft_length_o(l, ap);
	if (l->spec == 'o' || l->spec == 'O')
		tmp = ft_uitoa_base(nbr, 8);
	else if (l->spec == 'x')
		tmp = ft_uitoa_base(nbr, 16);
	else if (l->spec == 'X')
		tmp = ft_strupper(ft_uitoa_base(nbr, 16));
	else
		tmp = ft_uitoa_base(nbr, 10);
	s = ft_flags_o(l, nbr);
	str = ft_width(tmp, l, s);
	ft_putstr(str);
	i = i + ft_strlen(str);
	if (tmp != str)
		ft_strdel(&tmp);
	ft_strdel(&str);
	return (i);
}
