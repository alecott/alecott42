/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:37:42 by alecott           #+#    #+#             */
/*   Updated: 2018/01/23 18:25:33 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_filler
{
	int		mapX;
	int		mapY;
	int		pieceX;
	int		pieceY;
	int		X;
	int		Y;
	char	team;
	char	**map;
	char	**piece;
}				t_filler;

typedef struct	s_daewae
{
	int		x;
	int		y;
	int		i;
	int		j;
	struct s_daewae *next;
	struct s_daewae *prev;
}				t_daewae;

void			ft_map(t_filler *info, int fd);
void			ft_piece(t_filler *info, int fd);
int				ft_placement(t_filler * info);

#endif
