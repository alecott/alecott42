/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:03:06 by alecott           #+#    #+#             */
/*   Updated: 2018/05/30 13:04:59 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_print(t_ants *info)
{
	int		i;

	ft_putnbr(info->nb_ant);
	write(1, "\n", 1);
	i = 0;
	while (info->rooms[i])
	{
		ft_putendl(info->rooms[i]);
		i++;
	}
	i = 0;
	while (info->tubes[i])
	{
		ft_putendl(info->tubes[i]);
		i++;
	}
}
