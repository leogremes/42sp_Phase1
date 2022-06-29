/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:10:14 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/27 03:27:13 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_until(char *str, int index)
{
	char	*until;
	int		length;

	if (!str)
		return (NULL);
	length = ft_strlen(str);
	if (index < 0 || index >= length)
		index = length - 1;
	until = malloc((index + 2) * sizeof(char));
	if (!until)
		return (NULL);
	until[index + 1] = '\0';
	while (index >= 0)
	{
		until[index] = str[index];
		index--;
	}
	return (until);
}

static char	*get_after(char *str, int index)
{
	char	*after;
	int		length;
	int		i;

	if (!str)
		return (NULL);
	length = ft_strlen(str);
	if (index < 0 || index >= length - 1)
	{
		free(str);
		return (NULL);
	}
	i = length - index;
	after = malloc(i * sizeof(char));
	if (!after)
		return (NULL);
	i--;
	after[i] = '\0';
	while (i >= 0)
	{
		after[i] = str[index + 1 + i];
		i--;
	}
	free(str);
	return (after);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;
	int			nl_index;
	int			qty_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nl_index = ft_strseek(remainder, '\n');
	qty_read = 1;
	while (nl_index < 0 && qty_read > 0)
	{
		qty_read = read(fd, buffer, BUFFER_SIZE);
		if (qty_read >= 0)
		{
			buffer[qty_read] = '\0';
			remainder = ft_strjoin(remainder, buffer);
			nl_index = ft_strseek(remainder, '\n');
		}
	}
	line = get_until(remainder, nl_index);
	remainder = get_after(remainder, nl_index);
	free(buffer);
	return (line);
}
