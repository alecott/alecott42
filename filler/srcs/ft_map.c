/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:07:30 by alecott           #+#    #+#             */
/*   Updated: 2018/01/23 14:32:29 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		ft_map(t_filler *info, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	get_next_line(fd, &line);
	free(line);
	info->map = (char**)malloc(sizeof(char*) * info->mapY + 1);
	while (i < info->mapY && get_next_line(fd, &line))
	{
		tmp = ft_strsub(line, 4, info->mapX + 1);
		info->map[i] = tmp;
		ft_strdel(&tmp);
		ft_strdel(&line);
		ft_putstr(info->map[i]);
		ft_putchar('\n');
		i++;
	}
	info->map[i] = NULL;
}
