
#include "so_long.h"

void up_move(t_map *map)
{
    int x;
    int y;

    x = map->player.x;
    y = map->player.y;
    if (y > 0 && map->string[y - 1][x] != '1')
    {
        resume_move(map, x, y, UP);
        if (map->string[y - 1][x] == 'E' && (map->a != 0 || map->out == 1))
            return;
        map->moves++;
        draw_empty_tile(map, x, y);
        map->string[y][x] = '0';
        y--;
        print_movements(map);
        draw_empty_tile(map, x, y);
        draw_player_tile(map, x, y, UP);
        map->string[y][x] = 'P';
        map->player.x = x;
        map->player.y = y;
    }
}

void right_move(t_map *map)
{
    int x;
    int y;

    x = map->player.x;
    y = map->player.y;
    if (x < map->x - 1 && map->string[y][x + 1] != '1')
    {
        resume_move(map, x, y, RIGHT);
        if (map->string[y][x + 1] == 'E' && (map->a != 0 || map->out == 1))
            return;
        map->moves++;
        draw_empty_tile(map, x, y);
        map->string[y][x] = '0';
        x++;
        print_movements(map);
        draw_empty_tile(map, x, y);
        draw_player_tile(map, x, y, RIGHT);
        map->string[y][x] = 'P';
        map->player.x = x;
        map->player.y = y;
    }
}

void down_move(t_map *map)
{
    int x;
    int y;

    x = map->player.x;
    y = map->player.y;
    if (y < map->y - 1 && map->string[y + 1][x] != '1')
    {
        resume_move(map, x, y, DOWN);
        if (map->string[y + 1][x] == 'E' && (map->a != 0 || map->out == 1))
            return;
        map->moves++;
        draw_empty_tile(map, x, y);
        map->string[y][x] = '0';
        y++;
        print_movements(map);
        draw_empty_tile(map, x, y);
        draw_player_tile(map, x, y, DOWN);
        map->string[y][x] = 'P';
        map->player.x = x;
        map->player.y = y;
    }
}

void left_move(t_map *map)
{
    int x;
    int y;

	x = map->player.x;
	y = map->player.y;
    if (x > 0 && map->string[y][x - 1] != '1')
	{
        resume_move(map, x, y, LEFT);
        if (map->string[y][x - 1] == 'E' && (map->a != 0 || map->out == 1))
            return;
        map->moves++;
        draw_empty_tile(map, x, y);
        map->string[y][x] = '0';
        x--;
        print_movements(map);
        draw_empty_tile(map, x, y);
        draw_player_tile(map, x, y, LEFT);
        map->string[y][x] = 'P';
        map->player.x = x;
        map->player.y = y;
    }
}

int	key_hook(int keycode, t_map *map)
{
	scan_player(map);
	if (keycode == ESC)
		return (ft_destroy(map));
	else if (map->out == 1)
		return (0);
	else if (keycode == LEFT)
		left_move(map);
	else if (keycode == DOWN)
		move_down(map);
	else if (keycode == RIGHT)
		move_right(map);
	else if (keycode == UP)
		move_up(map);
	return (0);
}
