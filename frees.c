
#include "so_long.h"

int	ft_free_array(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

void	clean_up(t_map *map)
{
	if (map->string)
		free(map->string);
	if (map->temp)
		free(map->temp);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->file);
	exit(EXIT_FAILURE);
}
