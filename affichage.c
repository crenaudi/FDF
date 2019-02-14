/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:09:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/11 19:23:24 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		affichage(t_fdf *fdf, t_point **coord)
{
	int			x;
	int			y;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = 0;
		while (++x < fdf->x_max)
		{
			if (x < fdf->x_max)
				line(fdf, coord[y][x], coord[y][x + 1]);
			if (y < fdf->y_max)
				line(fdf, coord[y][x], coord[y + fdf->x_max][x]);
		}
	}
	ft_putstr("sortie");
	return (SUCCESS);
}
