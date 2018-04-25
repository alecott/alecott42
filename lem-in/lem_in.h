/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:13:35 by alecott           #+#    #+#             */
/*   Updated: 2018/04/25 17:08:32 by alecott          ###   ########.fr       */
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
	char	**tubes_names;
	char	**names;
	char	*start;
	char	*end;
	int		nb_room;
	int		nb_ant;
	char	**room_ant;
	char	**path_ant;
}				t_ants;

void	ft_lem_in(t_ants *info);
int		ft_stock(t_ants *info);
void	ft_names(t_ants *info);
void	ft_BFS(t_ants *info);
int		ft_error(t_ants *info);
char	*ft_find_dawae(t_ants *info, int ants);
char	*ft_link(char *room, char *tube, t_ants *info);
char	*ft_where_is_my_ant(t_ants *info, int ants);
int		ft_room_number(t_ants *info, char *room);
int		ft_norm(t_ants *info, int *i, int *j, int *n);
int		ft_check_ant(t_ants *info, char *room);
int		ft_tubestr(char *s1, char *s2);
int		ft_verify(char *look, char *end, t_ants *info);
void	ft_fill_path(t_ants info);
void	ft_algo(t_ants *info, char **path);
void	ft_tubes_names(t_ants *info);

#endif
