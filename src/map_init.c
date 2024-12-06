/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:20:52 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:27:18 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init(t_data *data)
{
	data->map.line = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->map.d_x = 0;
	data->map.d_y = 0;
	data->map.prize_len = 0;
	data->map.move = 0;
	data->map.prize_count = 0;
}

void	save_map(t_data *data, char *map)
{
	char	*line;
	int		i;
	int		len;
	int		fd;

	i = 0;
	len = map_len(map);
	if (len == -1)
		exit(1);
	data->map.line = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->map.line)
		return ;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->map.line[i] = get_line(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.line[i] = NULL;
	close (fd);
}

void	set_values(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.line[++i])
	{
		j = -1;
		while (data->map.line[i][++j])
		{
			if (data->map.line[i][j] == 'P')
			{
				data->map.p_x = j;
				data->map.p_y = i;
			}
			else if (data->map.line[i][j] == 'E')
			{
				data->map.d_x = j;
				data->map.d_y = i;
			}
			else if (data->map.line[i][j] == 'C')
				data->map.prize_len ++;
		}
	}
	data->map.height = i * SIZE_IMG;
	data->map.width = (ft_strlen(data->map.line[0])) * SIZE_IMG;
}

void	map_init(t_data *data, char *map)
{
	data_init(data);
	save_map(data, map);
	if (!data->map.line)
		return ;
	set_values(data);
}
