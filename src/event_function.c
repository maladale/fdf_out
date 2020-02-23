//
// Created by den_b_000 on 23.02.2020.
//

#include "fdf.h"

void	deal_key_move(int key, t_coord *data)
{
    if (key == 13)
        data->angle_x += 0.1;
    if (key == 1)
        data->angle_x -= 0.1;
    if (key == 0)
        data->angle_y += 0.1;
    if (key == 2)
        data->angle_y -= 0.1;
    if (key == 86)
        data->angle_z += 0.1;
    if (key == 88)
        data->angle_z -= 0.1;
    if (key == 126)
        data->move_y -= 15;
    if (key == 125)
        data->move_y += 15;
    if (key == 123)
        data->move_x -= 15;
    if (key == 124)
        data->move_x += 15;
}

void	deal_key2(int key, t_coord *data)

{
    if (key == 33)
    {
        data->angle_y = 0;
        data->angle_x = 0;
        data->angle_z = 0;
        data->diff_iso = 0;
    }
    if (key == 30)
    {
        data->angle_y = 0;
        data->angle_x = 0;
        data->angle_z = 0;
        data->diff_iso = 1;
    }
    if (key == 53)
        exit(0);
}

int		deal_key(int key, t_coord *data)

{
    if (key == 6)
        data->color_new *= 1.3;
    if (key == 7)
        data->color_new /= 1.3;
    if (key == 91)
    {
        if (data->z == -1 && (data->z += 1))
            data->z++;
    }
    if (key == 84)
    {
        if (data->z == 1 && (data->z -= 1))
            data->z--;
    }
    deal_key2(key, data);
    deal_key_move(key, data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}
