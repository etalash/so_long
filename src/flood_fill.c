/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:26 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 17:12:40 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'f')
		return ;
	map[y][x] = 'f';
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
}

char	**copy_map(t_data *data)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * ((data->map.height / SIZE_IMG) + 1));
	while (data->map.line[i])
	{
		str[i] = ft_strdup(data->map.line[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

int	is_map_valid(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'E' || ptr[i][j] == 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_path(t_data *data)
{
	char	**ptr;

	ptr = copy_map(data);
	flood_fill(ptr, data->map.p_y, data->map.p_x);
	if (is_map_valid(ptr) == -1)
	{
		free_ptr(ptr);
		return (-1);
	}
	free_ptr(ptr);
	return (0);
}
