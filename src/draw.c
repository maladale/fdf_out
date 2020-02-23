//
// Created by den_b_000 on 22.02.2020.
//
#include "fdf.h"

void show_menu(t_coord *our_coord)
{
    int		y;
    int		color;
    void	*mlx;
    void	*win;

    y = 0;
    color = 0xffffff;
    mlx = our_coord->mlx_ptr;
    win = our_coord->win_ptr;
    mlx_string_put(mlx, win, 65, y += 20, color, "How to Use");
    mlx_string_put(mlx, win, 15, y += 30, color, "Move: Arrows");
    mlx_string_put(mlx, win, 15, y += 30, color,
                   "Flatten: numpad keys 1 and 5");
    mlx_string_put(mlx, win, 15, y += 30, color, "Switch projection: keys [ ]");
    mlx_string_put(mlx, win, 15, y += 30, color, "Change colors Z and X");
    mlx_string_put(mlx, win, 57, y += 25, color, "");
    mlx_string_put(mlx, win, 57, y += 25, color, "");
    mlx_string_put(mlx, win, 57, y += 25, color, "");
    mlx_string_put(mlx, win, 15, y += 30, color, "");
    mlx_string_put(mlx, win, 57, y += 25, color, "");
    mlx_string_put(mlx, win, 57, y += 25, color, "");
}

void	move(t_line *line, float *x_step, float *y_step, t_coord *data)
{
    line->x += data->move_x;
    line->y += data->move_y;
    line->x1 += data->move_x;
    line->y1 += data->move_y;
    *x_step = line->x1 - line->x;
    *y_step = line->y1 - line->y;

} //??

void init_pict(t_coord *data)
{
    int x;
    int y;

    data->angle_y = 0;
    data->angle_x = 0;
    data->angle_z = 0;
    data->z = 1;
    data->angle = 0.82;
    x = 1500;
    y = 1000;
    data->move_x = x / 2;
    data->move_y = y / 3;
    data->diff_iso = 1;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, "FdF");
    data->color_new = 0x0f6fa4;
    draw(data);
}

void	bresenham(t_line line, t_coord *data)
{
    float	x_step;
    float	y_step;
    int		max;
    int		z;
    int		z1;

    z = data->matrix[(int)line.y][(int)line.x];
    z1 = data->matrix[(int)line.y1][(int)line.x1];
    check_iso(data, &z, &z1, &line);
    move(&line, &x_step, &y_step, data);
    max = my_max(my_abs(x_step), my_abs(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(line.x - line.x1) || (int)(line.y - line.y1))
    {
        if (z1 || z)
            data->color = get_light(get_color(data), 0xBBBBBB, 0.2);
        else
            data->color = get_color(data);
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, line.x,
                      line.y, data->color);
        line.x += x_step;
        line.y += y_step;
    }
}

void	draw(t_coord *data)
{
    t_line line;

    line.y = 0;
    show_menu(data);
    while (line.y < data->height)
    {
        line.x = 0;
        while (line.x < data->width)
        {
            if (line.x < data->width - 1)
            {
                line.x1 = line.x + 1;
                line.y1 = line.y;
                bresenham(line, data);
            }
            if (line.y < data->height - 1)
            {
                line.x1 = line.x;
                line.y1 = line.y + 1;
                bresenham(line, data);
            }
            line.x++;
        }
        line.y++;
    }
}
