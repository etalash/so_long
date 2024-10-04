/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:06:33 by stalash           #+#    #+#             */
/*   Updated: 2024/04/27 13:36:39 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

int		new_line(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	copy_list(t_list *list, char *str);
int		len_of_list(t_list *list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
char	*get_next_line(int fd);
char	*create_list(t_list **list, int fd);
void	add_to_the_end(t_list **list, char *buf, int fd);
char	*join_line(t_list *list);
void	clean_up_list(t_list **list);

#endif
