#include "fdf.h"

static  t_fdf   *new_point(t_fdf *tmp)
{
    t_fdf   *new;

    new = tmp->next;
    new->next = NULL;
    return (new);
}

static t_fdf     *coordonnees(char *line, int y, t_fdf *fdf)
{
    int     x;

    x = 0;
    ft_putstr(line);
    while (line[x] != 0)
    {
        ft_putstr("Print info\n");
        fdf->x = x;
        fdf->y = y;
        ft_putnbr(fdf->x);
        x++;
        if (line[x] != '0')
            fdf = new_point(fdf);
    }
    return (fdf);
}

void    stock_fdf(int fd)
{
    t_fdf   *fdf;
    char    *tmp;
    int x;
    int y;

    x = 0;
    y = 0;
    while (get_next_line(fd, &tmp))
    {
        fdf = coordonnees(tmp, y, fdf);
        //printf("%d\n %d\n %d\n", *(fdf->h), *(fdf->x), *(fdf->y));
        y++;
    }
}