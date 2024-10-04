/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:09:31 by stalash           #+#    #+#             */
/*   Updated: 2024/10/04 17:09:36 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void parameters_check(t_map *map)
// {
//     int     y;
//     int     x;
//     char    current_char;

//     y = 0;
//     map->a = 0;
//     map->b = 0;
//     map->p = 0;
//     while (y < map->y)
//     {
//         x = 0;
//         while (x < map->x)
//         {
//             current_char = map->string[y][x];
//             if (current_char == 'C')
//                 map->a++;
//             else if (current_char == 'E')
//                 map->b++;
//             else if (current_char == 'P')
//                 map->p++;
//             else if (current_char != '0' && current_char != '1')
//                 error_map_elements(map);
//             x++;
//         }
//         y++;
//     }
//     if (map->a < 1 || map->b < 1 || map->p != 1)
//         error_map_elements(map);
// }

static void	parameters_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		while (j < map->x)
		{
			if (map->string[i][j] == 'C')
				map->a += 1;
			else if (map->string[i][j] == 'E')
				map->b += 1;
			else if (map->string[i][j] == 'P')
				map->p += 1;
			else if (map->string[i][j] != '0' || map->string[i][j] != '1')
				error_map_elements(map);
			j++;
		}
		j = 0;
		i++;
	}
	if (map->a < 1 || map->b < 1 || map->p != 1)
		error_map_elements(map);
}

static void	wall_check(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map->string[0][x] != '\0')
	{
		if (map->string[0][x] != '1')
			error_wall(map);
		x++;
	}
	while (y < map->y - 1)
	{
		if (map->string[y][0] != '1' ||
			map->string[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->string[map->y - 1][x] != '\0')
	{
		if (map->string[map->y - 1][x] != '1')
			error_wall(map);
		x++;
	}
}

// static void wall_check(t_map *map)
// {
//     int i;
//     int j;

//     i = 0;
//     while (map->string[1][i] != '\0' && map->string[0][i] == '1')
//         i++;
//     if (map->string[1][i] != '\0')
//         error_wall(map);
//     j = 1;
//     while (j < map->y)
//     {
//         if (map->string[j][0] != '1' ||
//             map->string[j][map->x -1] != '1')
//             error_wall(map);
//         j++;
//     }
//     i = 0;
//     while(map->string[map->y - 1][i] == '1')
//         i++;
//     if (map->string[map->y - 1][i] != '\0')
//         error_wall(map);

// }

void	size_check(t_map *map)
{
	int	i;
	int	current_size;
	int	expected_size;

	i = 0;
	expected_size = ft_strlen(map->string[0]);
	while (i < map->y)
	{
		current_size = ft_strlen(map->string[i]);
		if (current_size != expected_size)
			error_size(map);
		i++;
	}
	map->x = expected_size;
}

static void	check_file_name(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->file_name);
	if (map->file_name[len - 1] != 'r')
		err_file_name();
	if (map->file_name[len - 2] != 'e')
		err_file_name();
	if (map->file_name[len - 3] != 'b')
		err_file_name();
	if (map->file_name[len - 4] != '.')
		err_file_name();
	if (!ft_strnstr(map->file_name, ".ber", ft_strlen(map->file_name)))
		err_file_name();
}

void	map_check(t_map *map)
{
	check_file_name(map);
	map_binary(map);
	size_check(map);
	wall_check(map);
	parameters_check(map);
	map_validity(map);
	ft_free_array(map->temp, map->y);
}
