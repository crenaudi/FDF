/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:36:34 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/15 18:12:05 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_p		*add_point(int x, int y, int z)
{
	t_p	*p;

	p = (t_p *)malloc(sizeof(t_p) * 1);
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
	p->next = NULL;
	return (p);
}

static void	coordonees(char **line, t_env *env, int x, int y)
{
	t_p	*p;
	int	z;

	z = ft_atoi(*line);
	env->z_min = (float)(z < env->z_min ? z : env->z_min);
	env->z_max = (float)(z > env->z_max ? z : env->z_max);
	p = add_point(x, y, z);
	if (env->p == NULL)
		env->p = p;
	else
	{
		p->next = env->p;
		env->p = p;
	}
	z = abs(z);
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
}

static int 	make_tab(int y, t_env *env)
{
	t_point *point;
	t_p		*p;
	int 	x;

	y = env->y_max;
	p = env->p;
	if (!(env->tab_p = (t_point **)malloc(sizeof(t_point *) * env->y_max)))
		return (ERROR);
	while (y--)
	{
		x = env->x_max;
		if (!(point = (t_point *)malloc(sizeof(t_point) * env->x_max)))
			return (ERROR);
		env->tab_p[y] = point;
		while (x--)
		{
			point[x].x = p->x;
			point[x].y = p->y;
			point[x].z = p->z;
			p = p->next;
		}
	}
	return (SUCCESS);
}

int		stock_env(int fd, t_env *env)
{
	char	*line;
	char	*line2;
	t_p		*p;
	int		x;
	int		y;

	y = 0;
	p = NULL;
	env->p = p;
	while (get_next_line(fd, &line) == 1)
	{
		line2 = line;
		x = 0;
		while (*line != '\0')
		{
			while (*line == ' ')
				line++;
			if (*line == '\0')
				break;
			coordonees(&line, env, x, y);
			line++;
			x++;
		}
		y++;
	}
	free(line2);
	env->x_max = x;
	env->y_max = y;
	make_tab(-1, env);
	return (SUCCESS);
}
