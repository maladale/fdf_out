//
// Created by den_b_000 on 19.09.2019.
//

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

char *ft_strdup(const char *s1)
{
    int		index;
    char	*tmp;
    char	*res;

    index = ft_strlen(s1);
    tmp = (char*)malloc(index + 1);
    if (!tmp)
    {
        errno = ENOMEM;
        return (NULL);
    }
    res = tmp;
    while ((*tmp++ = *s1++))
        *tmp = *s1;
    return (res);
}