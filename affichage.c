/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:09:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/03 19:56:21 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		affichage(t_fdf fdf, t_p *p)
{
	t_p			*x_max;
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	x_max = p;
	while (i++ <= fdf.x_max)
		x_max = x_max->next;
	while (y != fdf.y_max)
	{
		x = 0;
		while (x != fdf.x_max)
		{
			if (x <= fdf.x_max)
			{
				line(fdf, p, p->next);
				ft_putstr(" droite ");
			}
			if (y <= fdf.y_max)
			{
				line(fdf, p, x_max);
				x_max = x_max->next;
				ft_putstr(" bas ");
			}
		x++;
		p = p->next;
		}
		y++;
	}
	return (1);
}
