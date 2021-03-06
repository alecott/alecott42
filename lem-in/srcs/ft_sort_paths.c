/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:36:22 by alecott           #+#    #+#             */
/*   Updated: 2018/05/30 12:19:13 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	**ft_sort_paths(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	if (path == NULL)
		return (NULL);
	while (path[i])
	{
		if (path[i + 1])
		{
			if (ft_nbrooms_in_path(path[i]) > ft_nbrooms_in_path(path[i + 1]))
			{
				tmp = path[i];
				path[i] = path[i + 1];
				path[i + 1] = tmp;
				i = -1;
			}
		}
		i++;
	}
	return (path);
}
