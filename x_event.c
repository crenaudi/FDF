#include "fdf.h"
# define ESC 53

int     deal_key(int key, void *param)
{
    if (key == ESC)
        exit(0);  
}