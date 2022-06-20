/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:37:50 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/03 03:58:23 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_str(unsigned char c, const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	bef;
	size_t	aft;
	size_t	len;

	len = ft_strlen(s1);
	bef = 0;
	aft = 0;
	while (char_in_str(s1[bef], set) == 1)
		bef++;
	if (bef == len)
		return (ft_strdup(""));
	while (char_in_str(s1[len - 1 - aft], set) == 1)
		aft++;
	ret = (char *)malloc(len - bef - aft + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + bef, len - bef - aft + 1);
	return (ret);
}
