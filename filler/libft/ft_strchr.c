/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:59:00 by alecott           #+#    #+#             */
/*   Updated: 2017/12/19 04:18:31 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(s);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char*)s + i);
	return (NULL);
}
