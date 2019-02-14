/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/02/14 15:42:45 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	int		x;
	int		y;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd < 0 || ft_strstr(argv[1], ".fdf") == 0)
		is_error(-1);
	ft_bzero(&fdf, sizeof(fdf));
	fdf.mlx_ptr = mlx_init();

/* PRINT IMAGE
	fdf.img = mlx_new_image(fdf.img, 200, 200);
	fdf.img = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.sl, &fdf.endian);
	fill_pixel(fdf.img, 0, 0, 0xFFFFFF);
	mlx_putimage_to_window(data, fdf.win_ptr, 0, 0);
*/
	fdf.color = 0xBE93C5;
	fdf.e = 2;
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1024, 600, "mlx_42");
	stock_fdf(fd, &fdf);
	converte(&fdf);

	mlx_key_hook(fdf.win_ptr, deal_key, (void *)0);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
