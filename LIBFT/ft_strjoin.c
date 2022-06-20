/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:03:26 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/02 23:18:31 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		ret[s1_len + i] = s2[i];
		i++;
	}
	ret[s1_len + i] = '\0';
	return (ret);
}
