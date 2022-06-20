/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:47:38 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/03 03:18:42 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	total;

	total = nmemb * size;
	if (total / size != nmemb || total == 0)
		return (NULL);
	ret = malloc(total);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, total);
	return (ret);
}
