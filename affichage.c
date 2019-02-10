/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:09:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/09 14:30:10 by crenaudi         ###   ########.fr       */
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
	y = 1;
	x_max = p;
	while (i++ <= fdf.x_max)
		x_max = x_max->next;
	ft_putnbr(fdf.x_max);
	ft_putchar('\n');
	ft_putnbr(fdf.y_max);
	ft_putchar('\n');

	while (y < fdf.y_max)
	{
		x = 0;
		while (x < fdf.x_max)
		{
			if (x <= fdf.x_max)
				line(fdf, p, p->next);
			if (y < fdf.y_max && x_max != NULL && x_max->next != NULL)
			{
				line(fdf, p, x_max);
				x_max = x_max->next;
			}

		ft_putnbr(p->x);
		ft_putchar(' ');
		x++;
		p = p->next;
		}
		y++;
		ft_putnbr(p->y);
		ft_putchar('\n');
	}
	ft_putstr("sortie");
	return (1);
}
