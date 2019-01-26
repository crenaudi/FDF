#include "fdf.h"

t_p     *add_point(int x, int y, int z)
{
    t_p  *p;

    p = (t_p *)malloc(sizeof(t_p));
    p->x = x;
    p->y = y;
    p->z = z;
	p->next = NULL;
    return (p);
}

void    coordonees(char **line, t_fdf *fdf, int x, int y)
{
    t_p     *p;
    t_p     *next;
    int     z;

    z = ft_atoi(*line);
    p = add_point(x, y, z);
    next = fdf->p;
	if (next == NULL)
	{
		fdf->p = p;
	}
    else
    {
        while (next->next != NULL)
		    next = next->next;
	    next->next = p;
    }
    while (z > 9)
    {
        z = z / 10;
        (*line)++;
    }
}

int   stock_fdf(int fd, t_fdf *fdf)
{
    char    *line;
    int     x;
    int     y;

    y = 0;
    while (get_next_line(fd, &line) == 1 || y == 6)
    {
        x = 0;
        while (*line != '\0')
        {
            while (*line == ' ')
                line++;
            coordonees(&line, fdf, x, y);
            line++;
            x++;
        }
        y++;
    }
    return (1);
}