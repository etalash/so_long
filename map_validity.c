
#include "so_long.h"

void	map_binary(t_map *map)
{
	int		fd;
	char	*tem;

	map->y = 0;
	map->file = NULL;
	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		error_openfile();
	while ((map->line = get_next_line(fd)) != NULL)
	{
		tem = ft_strjoinfree(map->file, map->line);
		free(map->line);
		if (!tem)
		{
			close(fd);
			clean_up(map);
		}
		map->file = tem;
		map->y++;
	}
	close(fd);
	map->string = ft_split(map->file, '\n');
	map->temp = ft_split(map->file, '\n');
	if (!map->string || !map->temp)
	{
		clean_up(map);
	}
	free(map->file);
}

void	scan_player(t_map *map)
{
	int	found;
	int	y;
	int	x;

	found = 0;
	y = 0;
	while (y < map->y && !found)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->string[y][x] == 'P')
			{
				map->player.y = y;
				map->player.x = x;
				found = 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;

	type = map->temp[y][x];
	if (type == 'C')
		map->check_a -= 1;
	else if (type == 'E')
		map->check_b -= 1;
	else if (type == '0' || type == 'P')
		;
	else
		return ;
	map->temp[y][x] = '1';
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	map_validity(t_map *map)
{
	map->check_a = map->a;
	map->check_b = map->b;
	scan_player(map);
	move_on_paths(map->player.x, map->player.y, map);
	if (map->check_a != 0 || map->check_b >= map->b)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "NO VALID PATH\n\033[0m", 19);
		ft_free_array(map->string, map->y);
		ft_free_array(map->temp, map->y);
		exit(EXIT_FAILURE);
	}
}
