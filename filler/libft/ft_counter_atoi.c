/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:06:44 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 18:07:24 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counter_atoi(int counter, int m, int val)
{
	if (counter > 12 && m == 1)
		return (-1);
	if (counter > 12 && m == -1)
		return (0);
	else
	{
		val = val * m;
		return (val);
	}
}
