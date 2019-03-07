/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:23:03 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/07 16:38:38 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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

void	clean_image(t_env *env, t_img *img)
{
	mlx_destroy_image(env->mlx_ptr, img->ptr);
  ft_bzero(img, sizeof(t_img));
}

void	parciel_clean_env(t_env *env)
{
	clean_tab(env->tab_p, env->y_max);
	clean_image(env, env->img);
}
