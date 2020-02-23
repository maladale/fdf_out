//
// Created by den_b_000 on 22.02.2020.
//
#include "fdf.h"

int		close_app(t_coord *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
}

int		get_color(t_coord *data)
{
    return (data->color_new);
}

int		get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

void	isometric(float *x, float *y, int z, t_coord *data)
{
    *x = (*x - *y) * cos(data->angle);
    *y = (*x + *y) * sin(data->angle) - z;
}

void	check_iso(t_coord *data, int *z, int *z1, t_line *line)
{
    *z *= data->z;
    *z1 *= data->z;
    if (data->diff_iso)
    {
        isometric(&line->x, &line->y, *z, data);
        isometric(&line->x1, &line->y1, *z1, data);
    }
    rotate_x(&line->x, *z, data);
    rotate_x(&line->x1, *z1, data);
    rotate_y(&line->y, *z, data);
    rotate_y(&line->y1, *z1, data);
    rotate_z(&line->x, &line->y, data);
    rotate_z(&line->x1, &line->y1, data);
}