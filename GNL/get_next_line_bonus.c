/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:52:40 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/27 20:26:56 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_null_free(void *ptr_null, void *ptr_free)
{
	ptr_null = NULL;
	free(ptr_null);
	free(ptr_free);
	return (NULL);
}

static t_list	*get_list_node(t_list **lst, int file_d)
{
	t_list	*target;

	target = *lst;
	while (target && target->fd != file_d)
		target = target->next;
	if (!target)
	{
		target = ft_lstnew(file_d);
		if (target)
		{
			target->next = *lst;
			*lst = target;
		}
	}
	return (target);
}

static char	*get_until(char *str, char c)
{
	char	*until;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		i++;
	until = malloc((i + 1) * sizeof(char));
	if (!until)
		return (NULL);
	until[i] = '\0';
	while (--i >= 0)
		until[i] = str[i];
	return (until);
}

static char	*get_after(char *str, char c)
{
	char	*after;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (ft_null_free(NULL, str));
	j = i;
	while (str[j])
		j++;
	after = malloc((j - i + 1) * sizeof(char));
	if (!after)
		return (NULL);
	after[j - i] = '\0';
	while (--j - i >= 0)
		after[j - i] = str[j];
	free(str);
	return (after);
}

char	*get_next_line(int fd)
{
	static t_list	*store;
	t_list			*node;
	char			*buffer;
	char			*line;
	int				size_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	node = get_list_node(&store, fd);
	if (!buffer || !node)
		return (NULL);
	size_read = 1;
	while (size_read > 0 && ft_strseek(node->content, '\n') < 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read >= 0)
		{
			buffer[size_read] = '\0';
			node->content = ft_strjoin(node->content, buffer);
		}
	}
	line = get_until(node->content, '\n');
	node->content = get_after(node->content, '\n');
	ft_null_free(node, buffer);
	return (line);
}
