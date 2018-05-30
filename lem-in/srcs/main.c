/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:57:46 by alecott           #+#    #+#             */
/*   Updated: 2018/05/30 13:06:00 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_clean(t_ants info)
{
	int		i;

	i = 0;
	if (info.ultim_path == NULL)
		return ;
	while (info.ultim_path[i])
		ft_strdel(&info.ultim_path[i++]);
	ft_memdel((void**)info.ultim_path);
	free(info.ultim_path);
}

int			main(void)
{
	t_ants	info;

	ft_bzero(&info, sizeof(t_ants));
	if (!ft_stock(&info) || !ft_names(&info))
	{
		ft_putstr("ERROR");
		return (0);
	}
	ft_tubes_names(&info);
	if (!ft_error(&info))
	{
		ft_putstr("ERROR");
		return (0);
	}
	ft_fill_path(&info);
	ft_clean(info);
	return (0);
}
