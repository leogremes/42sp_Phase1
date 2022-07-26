/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:00:17 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:50 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_nbrlen_abs(int num, int base)
{
	int	len;

	len = 1;
	while (num >= base || num <= (base * -1))
	{
		len++;
		num = num / base;
	}
	return (len);
}

int	ft_nbrlen_uns(unsigned int num, unsigned int base)
{
	int	len;

	len = 1;
	while (num >= base)
	{
		len++;
		num = num / base;
	}
	return (len);
}

int	ft_nbrlen_long(unsigned long num, unsigned int base)
{
	int	len;

	len = 1;
	while (num >= base)
	{
		len++;
		num = num / base;
	}
	return (len);
}
