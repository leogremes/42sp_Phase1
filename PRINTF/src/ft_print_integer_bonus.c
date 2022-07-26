/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:15:49 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:02 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_int_left(int num, int filler, int signal, t_param *flags);
static int	print_int_filler(int num, int filler, t_param *flags);

int	print_integer(int num, t_param *flags)
{
	int	char_count;
	int	len;
	int	filler;
	int	signal;

	char_count = 0;
	if (num == 0 && flags->dot == 1 && flags->width == 0)
		return (print_zero_no_width(flags));
	char_count = 0;
	filler = 0;
	signal = 0;
	len = ft_nbrlen_abs(num, 10);
	if (flags->width > len)
		filler = flags->width - len;
	if (num < 0 || flags->plus == 1 || flags->space == 1)
		signal = 1;
	if (flags->size <= flags->width + signal)
		return (print_int_filler(num, filler, flags));
	if (flags->hyphen == 1)
		return (print_int_left(num, filler, len + filler + signal, flags));
	if (flags->zero == 1 && flags->dot == 0)
		return (print_int_filler(num, flags->size - len - signal, flags));
	while (--flags->size >= len + filler + signal)
		char_count += ft_putchar(' ');
	return (char_count + print_int_filler(num, filler, flags));
}

int	print_zero_no_width(t_param *flags)
{
	int	char_count;

	char_count = 0;
	while (--flags->size >= 0)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_int_left(int num, int filler, int len, t_param *flags)
{
	int	char_count;
	int	spaces_qty;

	spaces_qty = flags->size - len;
	char_count = print_int_filler(num, filler, flags);
	while (--spaces_qty >= 0)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_int_filler(int num, int filler, t_param *flags)
{
	int	char_count;

	char_count = 0;
	if (num < 0)
		char_count += ft_putchar('-');
	else if (flags->plus == 1)
		char_count += ft_putchar('+');
	else if (flags->space == 1)
		char_count += ft_putchar(' ');
	while (--filler >= 0)
		char_count += ft_putchar('0');
	return (char_count + ft_putnbr_abs(num, 10, 0));
}
