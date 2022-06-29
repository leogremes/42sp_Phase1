/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:52:48 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/27 20:26:34 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int file_d)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = file_d;
	new->content = NULL;
	new->next = NULL;
	return (new);
}

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strseek(char *str, char c)
{
	int	pos;

	if (str)
	{
		pos = 0;
		while (str[pos])
		{
			if (str[pos] == c)
				return (pos);
			pos++;
		}
	}
	return (-1);
}

char	*ft_strjoin(char *first, char *last)
{
	char	*join;
	int		first_len;
	int		last_len;
	int		i;

	first_len = ft_strlen(first);
	last_len = ft_strlen(last);
	if (first_len + last_len == 0)
		return (NULL);
	join = malloc((first_len + last_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < first_len)
		join[i] = first[i];
	i = -1;
	while (++i < last_len)
		join[i + first_len] = last[i];
	join[i + first_len] = '\0';
	if (first)
		free(first);
	return (join);
}
