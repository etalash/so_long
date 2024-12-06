/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:02 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:15:20 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	remove_prize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->image.player->instances[0].y != \
		data->image.prize->instances[i].y)
		i++;
	while (data->image.player->instances[0].x != \
		data->image.prize->instances[i].x)
		i++;
	j = data->image.prize->instances[i].enabled;
	data->image.prize->instances[i].enabled = 0;
	return (j);
}

void	move_image(t_data *data, int x, int y)
{
	if (y != 0)
	{
		data->map.p_y += y;
		data->image.player->instances[0].y += (SIZE_IMG * y);
	}
	else
	{
		data->map.p_x += x;
		data->image.player->instances[0].x += (SIZE_IMG * x);
	}
	data->map.move ++;
}

void	move(t_data *data, int x, int y)
{
	if (data->map.line[data->map.p_y + y][data->map.p_x + x] != '1')
	{
		move_image(data, x, y);
		if (data->map.line[data->map.p_y][data->map.p_x] == 'C')
			data->map.prize_count += remove_prize(data);
		else if (data->map.line[data->map.p_y][data->map.p_x] == 'E' && \
			data->map.prize_count == data->map.prize_len)
			mlx_close_window(data->mlx);
		if (data->map.prize_count == data->map.prize_len)
		{
			mlx_delete_image(data->mlx, data->image.door_closed);
			mlx_image_to_window(data->mlx, data->image.door_open, \
						SIZE_IMG * data->map.d_x, SIZE_IMG * data->map.d_y);
		}
		ft_printf("move %d\n", data->map.move);
	}
}

void	key_hook(mlx_key_data_t key_data, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data)
		return ;
	if (key_data.key == MLX_KEY_D && key_data.action == \
		MLX_PRESS)
		move(data, 1, 0);
	else if (key_data.key == MLX_KEY_A && key_data.action == \
		MLX_PRESS)
		move(data, -1, 0);
	else if (key_data.key == MLX_KEY_W && key_data.action == \
		MLX_PRESS)
		move(data, 0, -1);
	else if (key_data.key == MLX_KEY_S && key_data.action == \
		MLX_PRESS)
		move(data, 0, 1);
	else if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}
