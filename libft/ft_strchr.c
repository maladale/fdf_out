//
// Created by den_b_000 on 15.09.2019.
//

#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
    size_t count;
    char *ret;

    if (!s || !c)
        return (NULL);
    count = 0;
    while (*(s+count))
    {
        ret = (char *)(s + count);
        if (*(ret) == c)
            return (ret);
        count++;
    }
     return (NULL);
}
