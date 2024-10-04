/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:30:12 by stalash           #+#    #+#             */
/*   Updated: 2024/10/04 17:30:22 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map_elements(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed elements\n\033[0m", 21);
	ft_free_array(map->string, map->y);
	ft_free_array(map->temp, map->y);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed wall\n\033[0m", 17);
	ft_free_array(map->string, map->y);
	ft_free_array(map->temp, map->y);
	exit(EXIT_FAILURE);
}

void	error_size(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed size\n\033[0m", 17);
	ft_free_array(map->string, map->y);
	ft_free_array(map->temp, map->y);
	exit(EXIT_FAILURE);
}

void	err_file_name(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "Filename should be a BER extension file\n\033[0m", 45);
	exit(EXIT_FAILURE);
}

void	error_openfile(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed open\n\033[0m", 17);
	exit(EXIT_FAILURE);
}
