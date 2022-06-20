/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:22:49 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/07 21:07:38 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	elem_counter(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			ret++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (ret);
}

static size_t	index_next_char(const char *s, char c, size_t start)
{
	while (s[start] != c && s[start] != '\0')
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	st;
	size_t	qtt_elem;
	size_t	n_elem;

	qtt_elem = elem_counter(s, c);
	ret = malloc((qtt_elem + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	n_elem = 0;
	st = 0;
	while (s[st] != '\0')
	{
		while (s[st] == c)
			st++;
		if (s[st] != '\0')
		{
			ret[n_elem] = ft_substr(s, st, index_next_char(s, c, st) - st);
			n_elem++;
		}
		st = index_next_char(s, c, st);
	}
	ret[n_elem] = NULL;
	return (ret);
}
