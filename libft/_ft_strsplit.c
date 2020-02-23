//
// Created by den_b_000 on 19.09.2019.
//

#include <stdlib.h>
#include "ft_strncpy.c"

int  **init_ss (int n, char **res, int **str)
{
    unsigned int i;

    if (!str)
        return (NULL);
    i = 0;
    while (i < n) {
        res[i] = ft_strnew(10);
        if (!res[i])
            return (NULL);
        i++;
    }
    i = 0;
    while (i < n)
    {
        str[i] = (int *)malloc(4 * 2);
        if (!str[i])
            return (NULL);
        str[i][0] = -1;
        str[i][1] = -1;
        i++;
    }
    return (str);
}

int fill(char const *s, int **str, char c)
{
    int  i;
    int c_str;

    c_str = 0;
    i = -1;
    while (s[++i]) {
        if (s[i] != c)
        {
            if (str[c_str][0] < 0) {
                str[c_str][0] = i;
                str[c_str][1] = i;}
            else
                str[c_str][1] = i; }
        else if (str[c_str][0] < 0)
            continue;
        else
            if (str[c_str][0] >= 0)
                c_str++;
    }
    if (c_str == 0 && str[0][0] >=0)
        c_str = 1;
    return (c_str);
}

char **add_array(char **res, const char *s, size_t n)
{
    int c;

    c = 0;
    if (n) {
        while (res[c][0])
            c++;
        res[c] = ft_strncpy(res[c], s, n);
    }
    return (res);
}

char **ft_strsplit(char const *s, char c)
{
    char **res;
    int i;
    int c_str;
    int **str;
    int c_arr;

    if (!s)
        return (NULL);
    c_arr = ft_strlen(s)/2 + ft_strlen(s)%2 + 1;
    if ((res = (char **)malloc(c_arr * c_arr)) == NULL)
        return (NULL);
    if ((str = (int**)malloc(4 * c_arr)) == NULL)
        return (NULL);
    str = init_ss(c_arr, res, str);
    c_str = fill(s, str, c);
    i = -1;
    while (++i < c_arr)
        if (i <= c_str && str[i][0] >= 0)
            res = add_array(res, &s[str[i][0]], str[i][1] - str[i][0] + 1);
        else
            if (i > c_str)
                free(res[i]);
    free(str);
    return (res);
}