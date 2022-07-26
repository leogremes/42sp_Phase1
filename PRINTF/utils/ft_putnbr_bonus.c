/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:09:20 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:43 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	get_digit(int n, int upper);

int	ft_putnbr_abs(int num, int base, int upper)
{
	int	char_count;

	char_count = 0;
	if (num >= base || num <= (base * -1))
		char_count += ft_putnbr_abs(num / base, base, upper);
	return (char_count + ft_putchar(get_digit(num % base, upper)));
}

int	ft_putnbr_uns(unsigned int num, unsigned int base, int upper)
{
	int	char_count;

	char_count = 0;
	if (num >= base)
		char_count += ft_putnbr_uns(num / base, base, upper);
	return (char_count + ft_putchar(get_digit(num % base, upper)));
}

int	ft_putnbr_long(unsigned long num, unsigned int base, int upper)
{
	int	char_count;

	char_count = 0;
	if (num >= base)
		char_count += ft_putnbr_long(num / base, base, upper);
	return (char_count + ft_putchar(get_digit(num % base, upper)));
}

static char	get_digit(int n, int upper)
{
	if (n < 0)
		n = n * -1;
	if (n >= 0 && n <= 9)
		return (n + '0');
	if (upper == 1)
		return (n - 10 + 'A');
	return (n - 10 + 'a');
}
