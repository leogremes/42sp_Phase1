/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:43:04 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/01 17:22:30 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;
	size_t	big_len;

	lit_len = ft_strlen(little);
	big_len = ft_strlen(big);
	i = 0;
	if (little == NULL)
		return ((char *)big);
	if (lit_len > len)
		return (NULL);
	while (i + lit_len <= big_len && i + lit_len <= len)
	{
		if (ft_strncmp(big + i, little, lit_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
