//
// Created by den_b_000 on 18.09.2019.
//
#include <stdlib.h>
#include "libft.h"

char * ft_strsub(char const *s, unsigned int start, size_t len)
{
    int		count;
    char	*res;
    unsigned int tmp;

    if (!s)
        return (NULL);
    tmp = ft_strlen(s);
    if ((start < 0) || (len <= 0) ||
       ((start + len) <= 0) ||
       (!tmp) || (start > tmp))
        return (NULL);
    if ((start + len) > tmp)
        len = tmp - start;
    res = (char*)malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    count = 0;
    while (count < len)
    {
        res[count] = s[start + count];
        count++;
    }
    res[count] = '\0';
    return (res);
}