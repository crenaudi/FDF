#include "fdf.h"
# define ESC 53

int     deal_key(int key, void *param)
{
	int *i;

	i = (int *)param;
	if (key == ESC)
		exit(1);
	else if (key == UP)
		*i += 1;
	else if (key == DOWN)
		*i -= 1;
	else if (key == RIGHT)
		printf("%d\n", *i);
	return (0);
}

int     deal_mousse(int button, void *param)
{
	if (button == 1)
		ft_putstr("coucou");
	return (0);
}