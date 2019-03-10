/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/10 17:50:31 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "includes/fdf.h"

static int init_env(t_env *env)
{
	t_img *img;
	char c;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (ERROR);
	ft_bzero(img, sizeof(t_img));
	ft_bzero(env, sizeof(t_env));
	ft_putendl("init mlx");
	read(0, &c, 1);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, W_HEIGHT, "mlx_42");
	ft_putendl("ptr img");
	read(0, &c, 1);
	env->color = init_color(0x000000);
	img->ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT);
	printf("%p\n", img->ptr);
	ft_putendl("img data");
	read(0, &c, 1);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl, &img->endian));
	env->img = img;
	env->rot_map.x = deg2rad(-25);
	env->rot_map.y = deg2rad(-25);
	env->rot_map.z = deg2rad(25);
	env->scale = (float)20.0;
	env->c.x = 0.0;
	env->c.y = 0.0;
	env->c.z = 0.0;
	env->z_min = 0.0;
	env->z_max = 0.0;
	env->bertrand = 0;
	env->stop = 0;
	return (SUCCESS);
}

int	generate(t_env *env)
{
	converte(env);
	env->bertrand += 0.05;
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
	legend(env);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_env		env;
	int			fd;
	char 		c;

	ft_putendl("argc");
	read(0, &c, 1);
	if (argc != 2)
	{
		ft_putstr("Usage: ./env <filename>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd < 0 || ft_strcmp(ft_strstr(argv[1], ".fdf"), ".fdf") != 0)
		is_error(-1);
	ft_putendl("init env");
	read(0, &c, 1);
	if (init_env(&env) == ERROR)
		exit (0);
	ft_putendl("reccup coord");
	read(0, &c, 1);
	stock_env(fd, &env);
	ft_putendl("loop hook");
	read(0, &c, 1);
	mlx_loop_hook (env.mlx_ptr, generate, (void *)&env);
	mlx_key_hook(env.win_ptr, event, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
