/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:20:21 by alecott           #+#    #+#             */
/*   Updated: 2018/02/25 16:22:06 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_link(char *room, char *tube, t_ants *info)
{
	int		i;

	i = 0;
	while (info->names[i])
	{
		if (room != info->names[i] && ft_strstr(tube, info->names[i]))
			return (info->names[i]);
		i++;
	}
	return (NULL);
}
