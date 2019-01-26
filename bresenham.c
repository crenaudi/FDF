typedef struct s_line
{
    int     x1;
    int     y1;
    int     x2;
    int     y2;
}           t_line;

void    line(t_line line, int dx, int dy)
{
    int sx;
    int sy;
    int err;
    int e2;
 
    dx = abs(line->x2 - line->x1);
    dy = abs(line->y2 - line->y1);
    sx = line->x1 < line->x2 ? 1 : -1;
    sy = line->y1 < line->y2 ? 1 : -1; 
    err = (dx > dy ? dx : -dy) / 2;
    e2 = 0;
    while (1)
    {
        setPixel(line->x1 , line->y1);
        if (line->x1 == line->x2 && line->y1 == line->y2)
            return (0);
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            line->x1 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            line->y1 += sy;
        }
    }
}