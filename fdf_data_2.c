/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:36:34 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/27 17:02:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

typedef struct	s_gnl
{
        char	*line
	void	*next;
}


t_p		*add_point(int x, int y, int z)
{
	t_p	*p;

	p->x = x;
	p->y = y;
	p->z = z;
	p->next = NULL;
	return (p);
}

t_gnl	*coordonees(char *elem, t_p *p, int x, int y)
{
	t_p	*new;
	int	z;

	z = ft_atoi(elem);
	p = add_point(x, y, z);
	p->next = new;
	return (new);
}

t_gnl	*new_list(t_gnl *list)
{
        t_gnl     *new;

        line = NULL;
        list->next = new;
        new->next = NULL;
        return (new);
}

int		stock_fdf(int fd, t_fdf *fdf)
{
	t_gnl		*list;
	t_p		**p;
	char		**tab;
	int		x;
	int		y;

	y = 0;
	fdf->gnl = list;
	while (get_next_line(fd, &list->line) == 1)
		list = new_list(&list);
	fdf.p = p;
	list = fdf->gnl;
	while (list != NULL)
	{
		x = 0;
		tab = ft_strsplit(fdf->gnl, ' ');
		while (tab[x] != 0)
			p = coordonees(tab[x], &p, x, y);
			x++;
		}
		free(tab);
		list = list->next;
		y++;
	}
	fdf.x_max = x;
	free(list);
	return (1);
}
