/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where_is_my_ant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:30:15 by alecott           #+#    #+#             */
/*   Updated: 2018/03/02 17:08:52 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_where_is_my_ant(t_ants *info, int ants)
{
	int		i;
	int		j;

	i = 0;
	j = ft_tablen(info->names);
	while (i < j)
	{
		if (i != info->nb_start && i != info->nb_end &&
				info->rooms_state[i] == ants)
			return (info->names[i]);
		i++;
	}
	return (info->names[info->nb_start]);
}
