/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:37:42 by alecott           #+#    #+#             */
/*   Updated: 2018/01/29 17:21:28 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_filler
{
	int		mapx;
	int		mapy;
	int		piecex;
	int		piecey;
	int		x;
	int		y;
	char	team;
	char	**map;
	char	**piece;
}				t_filler;

typedef struct	s_daewae
{
	int				x;
	int				y;
	struct s_daewae	*next;
	struct s_daewae	*prev;
}				t_daewae;

void			ft_map(t_filler *info);
void			ft_piece(t_filler *info);
int				ft_placement(t_filler *info);
int				ft_score(t_filler *info, t_daewae *d);

#endif
