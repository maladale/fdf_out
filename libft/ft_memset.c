#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    char *p;
    int l;

    p = (char*)s;
    l=n;
    while(l-- > 0)
        *p++ = c;
    return s;
}
