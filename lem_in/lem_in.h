/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:13:35 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 18:40:08 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_ants
{
	char	**rooms;
	int		*rooms_state;
	char	**tubes;
	char	**names;
	char	*start;
	char	*end;
	int		nb_ant;
}				t_ants;

typedef struct	s_bfs
{
	char	**olds;
	char	**actuals;
	char	**news;
}				t_bfs;

void	ft_lem_in(t_ants *info);
int		ft_stock(t_ants *info);
void	ft_names(t_ants *info);
void	ft_BFS(t_ants *info);
int		ft_error(t_ants *info);
char	*ft_find_dawae(t_ants *info, int ants, int end, int start);
char	*ft_link(char *room, char *tube, t_ants *info);
char	*ft_where_is_my_ant(t_ants *info, int ants, int end, int start);
int		ft_room_number(t_ants *info, char *room);
int		ft_norm(t_ants *info, int *i, int *j, int *n);
int		ft_check_ant(t_ants *info, char *room);

#endif
