/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:24 by stalash           #+#    #+#             */
/*   Updated: 2024/10/11 18:12:31 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(t_data *data)
{
	int	count;

	count = 0;
	if (check_shape(data) == -1)
		count = ft_printf("\033[1;31m🛑ERROR:  failed size\n\033[0m");
	if (is_map_closed(data) == -1)
		count = ft_printf("\033[1;31m🛑ERROR: failed wall\n\033[0m");
	if (check_item(data) == -1 || valid_character(data) == -1)
		count = ft_printf("\033[1;31m🛑ERROR: failed elements\n\033[0m");
	if (valid_path(data) == -1)
		count = ft_printf("\033[1;31m🛑ERROR: failed Door\n\033[0m");
	if (count != 0)
	{
		free_ptr(data->map.line);
		return (-1);
	}
	return (0);
}

int	check_shape(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map.line[i])
		len += ft_strlen(data->map.line[i++]);
	if (((ft_strlen(data->map.line[0])) * i) == (size_t)len)
		return (0);
	return (-1);
}

int	is_map_closed(t_data *data)
{
	int	i;

	i = 0;
	if (ft_only(data->map.line[i], '1') == -1)
		return (-1);
	while (data->map.line[i + 1])
	{
		if (data->map.line[i][0] != '1' || data->map.line[i] \
			[ft_strlen(data->map.line[i]) - 1] != '1')
			return (-1);
		i++;
	}
	if (ft_only(data->map.line[i], '1') == -1)
		return (-1);
	return (0);
}

int	check_item(t_data *data)
{
	int	i;
	int	j;
	int	p_c;
	int	e_c;

	i = 0;
	j = 0;
	p_c = 0;
	e_c = 0;
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] == 'E')
				e_c ++;
			else if (data->map.line[i][j] == 'P')
				p_c ++;
			j++;
		}
		i++;
	}
	if (data->map.prize_len <= 0 || e_c != 1 || p_c != 1)
		return (-1);
	return (0);
}

int	valid_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] != '1' && data->map.line[i][j] != '0' \
				&& data->map.line[i][j] != 'E' && data->map.line[i][j] != 'P' \
				&& data->map.line[i][j] != 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
