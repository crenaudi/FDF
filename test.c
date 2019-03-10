# include <unistd.h>
# include "mlx.h"

int   deal_key(int key, void *param)
{
  if (key == 53)
    write(1, "c", 1);

	return (0);
}

int		main(void)
{
  void    *mlx;
  void    *win;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 500, 500, "mlx");
  mlx_pixel_put(mlx, win, 10, 10, 0xFFFFFF);
	mlx_loop_hook(mlx, deal_key, (void *)0);
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);
	return (0);
}
