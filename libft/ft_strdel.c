//
// Created by den_b_000 on 16.09.2019.
//

#include "ft_memdel.c"

void ft_strdel (char **as)
{
    if (as && *as)
        ft_memdel((void **)as);
}