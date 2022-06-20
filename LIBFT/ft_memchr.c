/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:36:40 by leda-sil          #+#    #+#             */
/*   Updated: 2022/05/31 23:25:32 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	check;
	char	*s;
	size_t	i;

	check = (unsigned char)c;
	s = (char *)str;
	i = 0;
	if (n == 0)
		return (NULL);
	while (s[i] != check)
	{
		if (i == n - 1)
			return (NULL);
		i++;
	}
	return ((void *)str + i);
}
