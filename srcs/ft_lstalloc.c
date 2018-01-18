/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:43:18 by alecott           #+#    #+#             */
/*   Updated: 2018/01/15 14:14:53 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_list		*ft_lstalloc(t_list *l)
{
	int		i;
	int		j;

	i = 0;
	while (ft_strchr("+-#0 ", l->content[i]))
		i++;
	l->flags = ft_memalloc(i);
	j = i;
	if (l->content[i] == '*')
		i++;
	while (l->content[i] >= '0' && l->content[i] <= '9')
		i++;
	l->width = ft_memalloc(i - j);
	j = i;
	if (l->content[i] == '.')
		i++;
	while ((l->content[i] >= '0' && l->content[i] <= '9')
			|| l->content[i] == '*')
		i++;
	l->precision = ft_memalloc(i - j);
	j = i;
	while (l->content[i] != l->spec && l->content[i])
		i++;
	l->length = ft_memalloc(i - j);
	return (l);
}
