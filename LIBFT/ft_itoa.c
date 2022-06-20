/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:57:59 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/03 18:27:05 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	qtt_digits(int n)
{
	unsigned int	qtt;

	if (n < 0)
		qtt = 1;
	else
		qtt = 0;
	while (n != 0)
	{
		qtt++;
		n = n / 10;
	}
	return (qtt);
}

char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	pos;

	if (n == 0)
		return (ft_strdup("0"));
	pos = qtt_digits(n);
	ret = (char *)malloc(pos + 1);
	if (ret == NULL)
		return (NULL);
	ret[pos] = '\0';
	pos--;
	if (n < 0)
		ret[0] = '-';
	else
		n = -n;
	while (n < 0)
	{
		ret[pos] = -(n % 10) + 48;
		n = n / 10;
		pos--;
	}
	return (ret);
}
