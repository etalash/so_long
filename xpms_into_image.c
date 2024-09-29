
#include "so_long.h"

void	xpms_into_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->image.empty = mlx_xpm_file_to_image(map->mlx,
			"image/empty.xpm", &a, &a);
	map->image.wall = mlx_xpm_file_to_image(map->mlx,
			"image/wall.xpm", &a, &a);
	map->image.exit = mlx_xpm_file_to_image(map->mlx,
			"image/door.xpm", &a, &a);
	map->image.collectible = mlx_xpm_file_to_image(map->mlx,
			"image/collectable.xpm", &a, &a);
	map->image.player = mlx_xpm_file_to_image(map->mlx,
			"image/player.xpm", &a, &a);
}
