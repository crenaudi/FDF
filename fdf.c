/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/21 19:30:02 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_fdf	fdf;

	int		fd;

	int		x;
	int		y;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd < 0 || ft_strstr(argv[1], ".fdf") == 0)
		is_error(-1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1024, 600, "mlx_42");

	if (stock_fdf(fd, &fdf) == 1)
		return (0);

	mlx_key_hook(win_ptr, deal_key, (void *)&i);
	//img_ptr = mlx_file_to_image(mlx_ptr, "42.fdf", &width, &height);
	//printf("%d\n %d\n", width, height);
	mlx_loop(mlx_ptr);
	return (0);
}
