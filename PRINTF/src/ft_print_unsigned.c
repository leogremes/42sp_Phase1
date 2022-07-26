/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:44 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 13:49:06 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_uns_left(unsigned int num, int filler, int spaces);
static int	print_uns_filler(unsigned int num, int filler);

int	print_unsigned(unsigned int num, t_param *flags)
{
	int	char_count;
	int	len;
	int	filler;

	char_count = 0;
	if (num == 0 && flags->dot == 1 && flags->width == 0)
		return (print_zero_no_width(flags));
	len = ft_nbrlen_uns(num, 10);
	filler = 0;
	if (flags->width > len)
		filler = flags->width - len;
	if (flags->size <= flags->width)
		return (print_uns_filler(num, filler));
	if (flags->hyphen == 1)
		return (print_uns_left(num, filler, flags->size - len - filler));
	if (flags->zero == 1 && flags->dot == 0)
		return (print_uns_filler(num, flags->size - len));
	while (--flags->size >= len + filler)
		char_count += ft_putchar(' ');
	return (char_count + print_uns_filler(num, filler));
}

static int	print_uns_left(unsigned int num, int filler, int spaces)
{
	int	char_count;

	char_count = print_uns_filler(num, filler);
	while (--spaces >= 0)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_uns_filler(unsigned int num, int filler)
{
	int	char_count;

	char_count = 0;
	while (--filler >= 0)
		char_count += ft_putchar('0');
	return (char_count + ft_putnbr_uns(num, 10, 0));
}
