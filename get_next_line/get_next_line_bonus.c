/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:15:05 by stalash           #+#    #+#             */
/*   Updated: 2024/04/27 13:36:37 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_up_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	if (!(*list))
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*join_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_of_list(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_list(list, next_str);
	return (next_str);
}

void	add_to_the_end(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

char	*create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!new_line(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		add_to_the_end(list, buf, fd);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		clean_up_list(&list[fd]);
		return (NULL);
	}
	create_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = join_line(list[fd]);
	if (!next_line)
	{
		clean_up_list(&list[fd]);
		return (NULL);
	}
	clean_up_list(&list[fd]);
	return (next_line);
}
