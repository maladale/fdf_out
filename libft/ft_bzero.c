//
// Created by den_b_000 on 11.09.2019.
//
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    char *p;

    p = (char*)s;
    ft_memset(s, '\0', n);
}

