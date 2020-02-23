//
// Created by den_b_000 on 13.09.2019.
//
//#include "get_next_line.h"

unsigned int ft_strlen(const char *s1)
{
    unsigned int count;

    count = 0;
    while (*(s1 + count))
        count++;
    return (count);
}

