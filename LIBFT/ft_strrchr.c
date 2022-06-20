/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:10:33 by leda-sil          #+#    #+#             */
/*   Updated: 2022/05/31 22:12:41 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	check;

	check = (char)c;
	i = ft_strlen(s);
	while (s[i] != check)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)s + i);
}
