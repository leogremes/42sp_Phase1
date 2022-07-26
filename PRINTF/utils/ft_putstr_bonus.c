/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:53:45 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:46 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(char *s)
{
	int	char_count;

	char_count = 0;
	if (!s)
		return (0);
	while (s[0] != '\0')
	{
		char_count += ft_putchar(s[0]);
		s++;
	}
	return (char_count);
}

int	ft_putstr_partial(char *s, int len)
{
	int	char_count;
	int	i;

	char_count = 0;
	if (s)
	{
		i = -1;
		while (++i < len && s[i] != '\0')
			char_count += ft_putchar(s[i]);
	}
	return (char_count);
}
