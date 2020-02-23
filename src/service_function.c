//
// Created by den_b_000 on 23.02.2020.
//
#include "fdf.h"

int	abs(int i)
{
    if (i < 0)
        return (-i);
    return (i);
} //??

int		max(int a, int b)
{
    return (a > b ? a : b);
} //??

void	rotate_x(float *x, int z, t_coord *data)

{
    int	new_x;
    int	new_z;

    if (data->angle_y)
    {
        new_x = *x * cos(data->angle + data->angle_y - 0.45)
                + z * -sin(data->angle + data->angle_y - 0.45);
        new_z = *x * sin(data->angle + data->angle_y - 0.45)
                + z * cos(data->angle + data->angle_y - 0.45);
        *x = new_x;
        z = new_z;
    }
}

void	rotate_y(float *y, int z, t_coord *data)
{
    int	new_y;
    int	new_z;

    if (data->angle_x)
    {
        new_y = *y * cos(data->angle + data->angle_x - 0.45)
                + z * sin(data->angle + data->angle_x - 0.45);
        new_z = *y * -sin(data->angle + data->angle_x - 0.45)
                + z * cos(data->angle + data->angle_x - 0.45);
        *y = new_y;
        z = new_z;
    }

}

void	rotate_z(float *x, float *y, t_coord *data)
{
    int	new_x;
    int	new_y;

    if (data->angle_z)
    {
        new_x = *x * cos(data->angle + data->angle_z - 0.85)
                + *y * sin(data->angle + data->angle_z - 0.85);
        new_y = *x * -sin(data->angle + data->angle_z - 0.85)
                + *y * cos(data->angle + data->angle_z - 0.85);
        *x = new_x;
        *y = new_y;
    }
}