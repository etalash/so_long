/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:36:56 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:44:35 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// my header file
# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"

// needed header files
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

// game needed vars
# define SIZE_IMG	40
# define SIZE_IMG	40

typedef struct s_map
{
	char	**line;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		d_x;
	int		d_y;
	int		prize_len;
	int		prize_count;
	int		move;
}t_map;

typedef struct s_image
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*prize;
	mlx_image_t	*player;
	mlx_image_t	*door_open;
	mlx_image_t	*door_closed;
}t_image;

// ******* the main struct **************

typedef struct s_data
{
	t_map		map;
	t_image		image;
	mlx_t		*mlx;
}t_data;

//********** initilize the map **********

void	map_init(t_data *data, char *map);
void	data_init(t_data *data);
void	save_map(t_data *data, char *map);
void	set_values(t_data *data);

//********* check the map ***************

int		check_map(t_data *data);
int		check_shape(t_data *data);
int		is_map_closed(t_data *data);
int		check_item(t_data *data);
int		valid_character(t_data *data);

//******** some helper functions *********

int		valid_path(t_data *data);
void	flood_fill(char **map, int y, int x);
char	**copy_map(t_data *data);
int		is_map_valid(char **ptr);

//******** display's functions ***********

void	display_background(t_data *data);
void	display_wall(t_data *data);
void	display_prize(t_data *data);
void	display_player_exit(t_data *data);

//******** */ moves && mlx_loop_hook ******

void	key_hook(mlx_key_data_t key_data, void *pointer);
void	move(t_data *data, int x2, int y2);
int		remove_prize(t_data *data);
void	move_image(t_data *data, int x, int y);

//*************** utils.c *****************

void	free_ptr(char **ptr);
int		map_len(char *map);
char	*get_line(char *str);

#endif
