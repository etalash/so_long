/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:18:17 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 17:19:08 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*load_image(t_data *data, char *str)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(str);
	image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	display_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->image.background = load_image(data, "images/black.png");
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			mlx_image_to_window(data->mlx, data->image.background, \
			SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
}

void	display_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->image.wall = load_image(data, "images/wall.png");
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] == '1')
				mlx_image_to_window(data->mlx, data->image.wall, \
				SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
}

void	display_prize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->image.prize = load_image(data, "images/prize.png");
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->image.prize, \
				SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
}

void	display_player_exit(t_data *data)
{
	data->image.door_closed = load_image(data, "images/door_closed.png");
	data->image.door_open = load_image(data, "images/door_open.png");
	data->image.player = load_image(data, "images/player.png");
	mlx_image_to_window(data->mlx, data->image.player, \
						SIZE_IMG * data->map.p_x, SIZE_IMG * data->map.p_y);
	mlx_image_to_window(data->mlx, data->image.door_closed, \
						SIZE_IMG * data->map.d_x, SIZE_IMG * data->map.d_y);
}
