# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;


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

void	clean_up_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + sizeof(char));
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] != '\0' && last_node->content[++i] != '\0')
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*make_line(t_list *list)
{
	char	*new_list;
	int		len;

	if (list == NULL)
		return (NULL);
	len = len_of_list(list);
	new_list = malloc(len + sizeof(char));
	if (new_list == NULL)
		return (NULL);
	copy_list(list, new_list);
	return (new_list);
}

void	add_to_the_end(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (new_line(*list) != 1)
	{
		buf = malloc(BUFFER_SIZE + sizeof(char));
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add_to_the_end(list, buf);

	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*str;
	t_list			*temp;

	if (read(fd, &str, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (list == NULL)
			return (NULL);
		while (list != NULL)
		{
			temp = (list)->next;
			free((list)->content);
			free(list);
			list = temp;
		}
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	str = make_line(list);
	clean_up_list(&list);
	return (str);
}
