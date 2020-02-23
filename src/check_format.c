//
// Created by den_b_000 on 22.02.2020.
//

#include "fdf.h"

int count_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i] != NULL)
        i++;
    return (i);
}

int count_sym(char const *s, char c)
{
    int	count;

    count = 0;
    while (*s != '\0')
    {
        if (*s == c && *s != '\0')
            s++;
        else
        {
            while (*s != c && *s != '\0')
                s++;
            count++;
        }
    }
    return (count);
} //??

int check_dim(char **argv)
{
    int width;
    int height;
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY, 0);
    get_next_line(fd, &line);
    width = count_sym(line, ' ');
    while (get_next_line(fd, &line) > 0)
    {
        height = count_sym(line, ' ');
        free(line);
        if (height != width)  //? is not squre
            return (0);
    }
    return (1);
} //??

int check_format(int argc, char **argv) ///
{
    int fd;

    if (argc!=2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0 || !fd)
        return (0);
    if (read(fd, NULL, 0) < 0)
    {
        close(fd);
        return (0);
    }
    return (check_dim(argv));
}
