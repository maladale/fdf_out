//
// Created by den_b_000 on 18.09.2019.
//
#include <stdlib.h>
//#include "get_next_line.h"

unsigned int ft_strlen(const char *s1);

char * ft_strjoin(char const *s1, char const *s2)
{
    char *res;
    unsigned int  len;
    unsigned int  count;
    unsigned int len1;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len = len1 + ft_strlen(s2);
    res = (char *)malloc(len + 1);
    if (!res)
        return (NULL);
    count = 0;
     while (count < len)
     {
         if (count < len1)
             res[count] = s1[count];
         else
             res[count] = s2[count - len1];
         count++;
     }
     res[count] = '\0';
     return (res);
}
