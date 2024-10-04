/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:24:20 by stalash           #+#    #+#             */
/*   Updated: 2024/10/04 17:38:25 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define IMG_PXL 50
# define WND_NAME "so_long"

typedef struct s_player
{
	int	x;
	int	y;

}	t_player;

typedef struct s_image
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player;
}	t_image;

typedef struct s_map
{
	int			x;
	int			y;
	int			a;
	int			b;
	int			check_a;
	int			check_b;
	int			p;
	int			fd;
	char		*line;
	char		*file;
	char		**string;
	char		**temp;
	char		*file_name;
	int			out;
	int			moves;
	void		*mlx;
	void		*win_ptr;
	t_image		image;
	t_player	player;
}	t_map;

//     ERRORS & FREES

void	error_map_elements(t_map *map);
void	error_wall(t_map *map);
void	error_size(t_map *map);
void	err_file_name(void);
void	error_openfile(void);
void	clean_up(t_map *map);
int		ft_free_array(char **ret, int i);

//     FUCTIONS

void	map_check(t_map *map);
char	*ft_strjoinfree(char *s1, char *s2);
void	map_binary(t_map *map);
void	map_validity(t_map *map);
void	scan_player(t_map *map);
void	xpms_into_image(t_map *map);
void	build_window(t_map *map);
int		key_hook(int keycode, t_map *map);
int		ft_destroy(t_map *map);
void	draw_empty_tile(t_map *map, int x, int y);
void	draw_player_tile(t_map *map, int x, int y, int direction);
void	resume_move(t_map *map, int x, int y, int dir);
void	print_movements_alt(t_map *map);
void	ft_win(t_map *map);

#endif

// int			fd;
// char		*line;
// char		*file;
// char		**array;
// char		**copy;
// char		*filename;
// int			y;
// int			x;
// int			c;
// int			e;
// int			c_check;
// int			e_check;
// int			p;
// int			exit;
// int			moves;
// void		*mlx;
// void		*wnd;
// t_img		img;
// t_player	player;
