//
// Created by den_b_000 on 17.02.2020.
//

#include "fdf.h"

int check_arr(char **arr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (arr[i++])
    {
        while (arr[i-1][j++])
            if (!(ft_isdigit(arr[i-1][j-1])  \
            || (arr[i-1][j-1] >= 'A' && arr[i-1][j-1] <= 'F') \
            || (arr[i-1][j-1] >= 'a' && arr[i-1][j-1] <= 'f') \
            ||  arr[i-1][j-1] == 'x' || arr[i-1][j-1] == ','))
                return (0);
        j = 0;
    }
    return (1);
}  //??

int *check_file(char *filename, int *dim)
{
    int fd;
    char *line;
    char **spl_str;
    int width;

    width=0;
    fd = open(filename, O_RDONLY);
    spl_str = NULL;
    if (fd < 0 || !fd)
        return (NULL);
        while (get_next_line(fd, &line) > 0)
        {
            spl_str = ft_strsplit(line, ' ');
            dim[1] = count_arr(spl_str);
            dim[1] = (check_arr(spl_str) ? dim[1] : 0);
            width++;
        }
    dim[0] = width;
    free(line);
    free(spl_str);
    close(fd);
    return (dim); //&dim
} //??

int assign_coord(int **matrix, int width, char *line, int dim)
{
    char **spl_str;
    int height;

    matrix[width] = (int *)malloc(sizeof(int) * dim);
    if (!matrix[width])
        return (0);
    if (!(spl_str = ft_strsplit(line, ' ')))
        return (0);
    height= 0;
     while (spl_str[height++]) {
         matrix[width][height-1] = ft_atoi(spl_str[height-1]);
     }
    free(spl_str);
    return (1);
} //??

t_coord *read_file(char *filename, t_coord *our_coord)
{
    int *dim;
    char *line;
    int width;
    int fd;

    dim = (int*)malloc(sizeof(int) * 2);
    if (!dim)
        return (NULL);
    dim = check_file(filename, dim);
    if (!dim || !dim[0] || !dim[1])
        return (NULL);
    width = 0;
    fd = open(filename, O_RDONLY);
    our_coord->matrix = (int **)malloc(sizeof(int) * dim[0]);
    while (get_next_line(fd, &line) > 0) {
        assign_coord(our_coord->matrix, width++, line, dim[1]);
    }
    free(line);
    free(dim);
    close(fd);
    return (our_coord);
}

