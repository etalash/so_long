/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:48 by stalash           #+#    #+#             */
/*   Updated: 2024/04/12 17:04:38 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] && BUFFER_SIZE > i)
		{
			if (list->content[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	copy_list(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->content[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_of_list(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	dealloc(t_list **list, t_list *clean_node, char *str)
{
	t_list	*temp;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->content[0] != 0)
		*list = clean_node;
	else
	{
		free(str);
		free(clean_node);
	}
}
