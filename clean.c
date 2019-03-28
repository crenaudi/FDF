/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:23:03 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/10 19:47:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	is_error(int i)
{
	if (i == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (i == 0)
		exit(EXIT_SUCCESS);
}

void	clean_tab(t_point **coord, int coord_y)
{
	int i;

	i = 0;
	while (i < coord_y)
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

void	clean_image(t_img *img)
{
	ft_bzero(img->data, WIN_W * WIN_H * (img->bpp / 8));
}

void	kill_image(t_env *env, t_img *img)
{
	mlx_destroy_image(env->mlx_ptr, img->ptr);
	free(img);
}

static void destroy_list(t_p *p)
{
	t_p	*tmp;

	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(tmp);
}

void	parciel_clean_env(t_env *env)
{
	clean_tab(env->tab_p, env->y_max);
	clean_tab(env->tab_m, env->y_max);
	destroy_list(env->p);
	kill_image(env, env->img);
}
