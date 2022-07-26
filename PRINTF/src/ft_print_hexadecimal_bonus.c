/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:03:32 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:08:58 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_hex_filler(unsigned int num, int filler, t_param *flags);
static int	print_hex_left(int num, int filler, int len, t_param *flags);

int	print_hexadecimal(unsigned int num, t_param *flags)
{
	int	char_count;
	int	len;
	int	filler;
	int	prefix;

	char_count = 0;
	if (num == 0 && flags->dot == 1 && flags->width == 0)
		return (print_zero_no_width(flags));
	filler = 0;
	prefix = 0;
	len = ft_nbrlen_uns(num, 16);
	if (flags->width > len)
		filler = flags->width - len;
	if (num != 0 && flags->sharp == 1)
		prefix = 2;
	if (flags->size <= flags->width + prefix)
		return (print_hex_filler(num, filler, flags));
	if (flags->hyphen == 1)
		return (print_hex_left((int)num, filler, len + filler + prefix, flags));
	if (flags->zero == 1 && flags->dot == 0)
		return (print_hex_filler(num, flags->size - len - prefix, flags));
	while (--flags->size >= len + filler + prefix)
		char_count += ft_putchar(' ');
	return (char_count + print_hex_filler(num, filler, flags));
}

static int	print_hex_left(int num, int filler, int len, t_param *flags)
{
	unsigned int	number;
	int				space_qty;
	int				char_count;

	number = (unsigned int)num;
	space_qty = flags->size - len;
	char_count = print_hex_filler(number, filler, flags);
	while (--space_qty >= 0)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_hex_filler(unsigned int num, int filler, t_param *flags)
{
	int	char_count;
	int	upper;

	char_count = 0;
	upper = 0;
	if (flags->type == 'X')
		upper = 1;
	if (num != 0 && flags->sharp == 1 && upper == 1)
		char_count += ft_putstr("0X");
	if (num != 0 && flags->sharp == 1 && upper == 0)
		char_count += ft_putstr("0x");
	while (--filler >= 0)
		char_count += ft_putchar('0');
	return (char_count + ft_putnbr_uns(num, 16, upper));
}
