
#include "so_long.h"

int	ft_destroy(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win_ptr);
	ft_free_array(map->string, map->y);
	exit(EXIT_SUCCESS);
	return (0);
}

void    map_initialization(t_map *map, char **argv)
{
    map->file_name = argv[1];
    map->a = 0;
    map->b = 0;
    map->y = 0;
    map->p = 0;
    map->moves = 0;
    map->player.x = 0;
    map->player.y = 0;
    map->out = 0;
}

// int main(int argc, char **argv)
// {
//     t_map  *map;

//     if (argc == 2)
//     {
//         map_initialization(map, argv);
//         map_check(map);
//         map->mlx = mlx_init();
//         map->win_ptr = mlx_new_window(map->mlx, map->x
//                      * IMG_PXL, map->y * IMG_PXL, WND_NAME);
//         xpms_into_image(map);
//         build_window(map);
//         mlx_hook(map->win_ptr, 17, 0, ft_destroy, map);
//         mlx_key_hook(map->win_ptr, key_hook, map);
//         mlx_loop(map->mlx);
//     }
//     write(2, "\033[1;31m❌ERROR:", 16);
//     write(2, " Please provide a valid map file as an argument!\n\033[0m", 53);
//     exit(EXIT_FAILURE);
// }

int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        write(2, "\033[1;31m❌ERROR:", 16);
        write(2, " Please provide a valid map file as an argument!\n\033[0m", 53);
        return (EXIT_FAILURE);
    }
    map_initialization(&map, argv);
    map_check(&map);
    map->mlx = mlx_init();
    if (!map->mlx)
    {
        write(2, "\033[1;31m❌ERROR:", 16);
        write(2, " Failed to initialize graphics engine.\n\033[0m", 45);
        return (EXIT_FAILURE);
    }
    map->win_ptr = mlx_new_window(map->mlx, map->x * IMG_PXL, map->y * IMG_PXL, WND_NAME);
    xpms_into_image(&map);
    build_window(&map);
    mlx_hook(map->win_ptr, 17, 0, ft_destroy, &map);
    mlx_key_hook(map->win_ptr, key_hook, &map);
    mlx_loop(map->mlx);

    return (0);
}
