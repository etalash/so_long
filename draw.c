/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:29:47 by stalash           #+#    #+#             */
/*   Updated: 2024/10/04 17:29:50 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_empty_tile(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win_ptr, map->image.empty, \
							x * IMG_PXL, y * IMG_PXL);
}

void	draw_player_tile(t_map *map, int x, int y, int direction)
{
	if (direction == LEFT)
		mlx_put_image_to_window(map->mlx, map->win_ptr, \
								map->image.player, \
								x * IMG_PXL + 8, y * IMG_PXL);
}

void	print_movements_alt(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	if (move != NULL)
	{
		if (write(1, "\r", 1) == -1)
		{
			free(move);
			return ;
		}
		write(1, "\033[1;33m", 7);
		if (write(1, move, ft_strlen(move)) == -1)
		{
			free(move);
			return ;
		}
		write(1, "\033[0m", 4);
		write(1, " movements", 10);
	}
	free(move);
}

void	resume_move(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	else if (dir == DOWN)
		y += 1;
	else if (dir == LEFT)
		x -= 1;
	else if (dir == RIGHT)
		x += 1;
	else
		return ;
	if (map->string[y][x] == 'E')
	{
		if (map->a == 0)
		{
			ft_win(map);
			return ;
		}
		else
			return ;
	}
	if (map->string[y][x] == 'C')
	{
		map->string[y][x] = '0';
		map->a--;
	}
}
