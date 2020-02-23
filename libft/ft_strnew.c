//
// Created by den_b_000 on 16.09.2019.
//
#include "ft_bzero.c"
#include <stdlib.h>

char *ft_strnew(size_t size)
{
    char *ret_val;

    if (size <= 0)
        return (NULL);
    ret_val = (char*)malloc(size + 1);
    if (!ret_val)
        return  (NULL);
    else{
        ft_bzero(ret_val, size + 1);
        return (ret_val);
    }
}

