/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:47:46 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 10:14:59 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_len(uintmax_t nbr, int base)
{
	int		n;

	n = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		n++;
		nbr = nbr / base;
	}
	return (n);
}

char		*ft_uitoa_base(uintmax_t nbr, int base)
{
	char	*str;
	int		len;

	len = ft_len(nbr, base);
	str = ft_memalloc(sizeof(*str) * (len + 1));
	while (len >= 0)
	{
		len--;
		if ((nbr % base) < 10 && str[len] != '-')
			str[len] = nbr % base + '0';
		else if (str[len] != '-')
			str[len] = ((nbr % base) + 87);
		nbr = nbr / base;
	}
	return (str);
}
