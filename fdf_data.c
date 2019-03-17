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

	p = (t_p *)malloc(sizeof(t_p));
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
	while (**line != ' ' && **line != '\0')
		(*line)++;
}

static t_point 	**make_tab(int y, t_env *env)
{
	t_point **tab;
	t_point *point;
	t_p		*p;
	int 	x;

	y = env->y_max;
	p = env->p;
	if (!(tab = (t_point **)malloc(sizeof(t_point *) * env->y_max)))
		return (NULL);
	while (y--)
	{
		x = env->x_max;
		if (!(point = (t_point *)malloc(sizeof(t_point) * env->x_max)))
			return (NULL);

		tab[y] = point;
		while (x--)
		{
			point[x].x = p->x;
			point[x].y = p->y;
			point[x].z = p->z;
			//ft_putnbr(p->z);
			//ft_putchar(' ');
			p = p->next;
		}
		//ft_putnbr(y);
		//ft_putchar('\n');
	}
	return (tab);
}

static void complete_env(t_env *env, int x, int y)
{
	env->x_max = x;
	env->y_max = y;
	env->tab_p = make_tab(-1, env);
	env->tab_m = make_tab(-1, env);
}

int		stock_env(int fd, t_env *env)
{
	char	*line2;
	t_p		*p;
	t_vec2 index;

	index.y = 0;
	p = NULL;
	env->p = p;
	while (get_next_line(fd, &env->line) == 1)
	{
		line2 = env->line;
		index.x = 0;
		while (*env->line != '\0')
		{
			while (*env->line == ' ')
				env->line++;
			if (*env->line == '\0')
				break;
			coordonees(&env->line, env, index.x, index.y);
			index.x++;
		}
		free(line2);
		index.y++;
	}
	complete_env(env, index.x, index.y);
	return (SUCCESS);
}
