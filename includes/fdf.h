//
// Created by den_b_000 on 17.02.2020.
//

# include "libft.h"
# include <math.h>
//# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef FDF_H
#   define FDF_H

typedef struct		str_coord
{
    float		height;
    float		width;
    //float		altitude;
    int         **matrix;
    int         z;
    float         angle_x;
    float         angle_y;
    float         angle_z;
    int         move_x;
    int         move_y;
    float       angle;
    int			color;
    int		color_new;
    int         diff_iso;
    void		*mlx_ptr;
    void		*win_ptr;
}					t_coord;

typedef	struct	s_line
{
    float x;
    float y;
    float x1;
    float y1;
}				t_line;

int				count_arr(char **str); //
int				get_color(t_coord *data); //
int				get_light(int start, int end, double percentage); //
int				close_app(t_coord *data); //
int				deal_key(int key, t_coord *data); //
int			    init_pict(t_coord *param); //
void			read_file(char *file_name, t_coord *data); //
void			bresenham(t_line line, t_coord *data); //
void			draw(t_coord *data); //
void			check_format(int argc, char **argv); //
void			show_menu(t_coord *data); //
void			isometric(float *x, float *y, int z, t_coord *data); //
void			check_iso(t_coord *data, int *z, int *z1, t_line *line); //
void			deal_key_move(int key, t_coord *data); //
void			deal_key2(int key, t_coord *data); //
void			rotate_x(float *x, int z, t_coord *data); //
void			rotate_y(float *y, int z, t_coord *data); //
void			rotate_z(float *x, float *y, t_coord *data); //

#endif //FDF_H
