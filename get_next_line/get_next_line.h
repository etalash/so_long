/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:22:43 by stalash           #+#    #+#             */
/*   Updated: 2024/04/12 16:52:33 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

int		new_line(t_list *list);
t_list	*ft_lstlast(t_list *list);
char	*make_line(t_list *list);
void	copy_list(t_list *list, char *ptr);
int		len_of_list(t_list *list);
// void	clean_up_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	create_list(t_list **list, int fd);
void	clean_up_list(t_list **list);

#endif
