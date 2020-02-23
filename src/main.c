#include <stdio.h>
#include "fdf.h"

int main(int argc, char **argv)
{
    t_coord *our_coord;
//++ all check in read_file
    if (!check_format(argc, argv)) {
        printf("Invalid data\n");
        return (0);
    }
    //-- all check in read_file
    our_coord = (t_coord*)malloc(sizeof(t_coord));
    if (!our_coord) {
        return (0);
    }
    if (!read_file(argv[1], our_coord))
    {
        printf("Can't read file %s\n", argv[1]);
        free(our_coord);
        return (0);
    }
    init_pict(our_coord);
    mlx_hook(our_coord->win_ptr, 2, 0, deal_key, our_coord);
    mlx_hook(our_coord->win_ptr, 17, 0, close_app, our_coord);
    mlx_loop(our_coord->mlx_ptr);
    if (our_coord)
        free(our_coord);
    return (0);
}
