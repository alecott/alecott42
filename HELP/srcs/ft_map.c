/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:07:30 by alecott           #+#    #+#             */
/*   Updated: 2018/01/27 18:26:32 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		ft_map(t_filler *info)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	info->map = (char**)malloc(sizeof(char*) * info->mapy + 1);
	while (i < info->mapy)
	{
		get_next_line(0, &line);
		info->map[i] = ft_strsub(line, 4, info->mapx);
		ft_strdel(&line);
		i++;
	}
	info->map[i] = NULL;
}
