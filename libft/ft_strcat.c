//
// Created by den_b_000 on 23.09.2019.
//
#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
    int	c;
    int	dest_end;

    c= -1;
    dest_end = ft_strlen(dest);
    while (src[++c])
    {
        dest[dest_end] = src[c];
        dest_end++;
    }
    dest[dest_end] = '\0';
    return (dest);
}