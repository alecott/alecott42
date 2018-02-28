/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where_is_my_ant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:30:15 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 09:07:21 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_where_is_my_ant(t_ants *info, int ants, int end, int start)
{
	int		i;
	int		j;

	i = 0;
	j = ft_tablen(info->names);
	while (i < j)
	{
		if (i != start && i != end && info->rooms_state[i] == ants)
			return (info->names[i]);
		i++;
	}
	return (info->names[start]);
}
