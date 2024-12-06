/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:51 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:28:50 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_line(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	map_len(char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd <= 0 || read(fd, 0, 0) < 0)
	{
		ft_printf("\033[1;31m❌ERROR: No such File \n\033[0m");
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
