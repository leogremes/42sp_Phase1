/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:10:17 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/23 18:18:49 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
