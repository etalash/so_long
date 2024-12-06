/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:19 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:12:00 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int args, char **argv)
{
	t_data	data;

	if (args != 2)
	{
		write(2, "\033[1;31m❌ERROR:", 16);
		write(2, " Please provide a valid map file!\n\033[0m", 53);
		return (EXIT_FAILURE);
	}
	map_init(&data, argv[1]);
	if (check_map(&data) == -1)
		return (1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx = mlx_init(data.map.width, data.map.height, "SO_LONG 42", 1);
	if (!data.mlx)
		return (1);
	display_background(&data);
	display_wall(&data);
	display_prize(&data);
	display_player_exit(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
