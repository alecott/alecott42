/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:37:23 by alecott           #+#    #+#             */
/*   Updated: 2018/01/27 18:32:04 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			ft_score(t_filler *info, t_daewae *d)
{
	int		ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			if (info->map[i][j] != info->team && info->map[i][j] != '.')
			{
				if (ret == 0)
					ret = FT_ABS(i - d->y) + FT_ABS(j - d->x);
				else if ((FT_ABS(i - d->y) + FT_ABS(j - d->x)) < ret)
					ret = FT_ABS(i - d->y) + FT_ABS(j - d->x);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}
