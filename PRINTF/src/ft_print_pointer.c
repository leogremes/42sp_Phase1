/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:11:52 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/21 16:33:21 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer_null(t_param *flags);

int	print_pointer(void *ptr, t_param *flags)
{
	int				char_count;
	int				len;
	unsigned long	address;

	if (!ptr)
		return (print_pointer_null(flags));
	char_count = 0;
	address = ptr - NULL;
	len = 2 + ft_nbrlen_long(address, 16);
	if (flags->size <= len)
		return (ft_putstr("0x") + ft_putnbr_long(address, 16, 0));
	while (flags->hyphen == 0 && --flags->size >= len)
		char_count += ft_putchar(' ');
	char_count += ft_putstr("0x");
	char_count += ft_putnbr_long(address, 16, 0);
	while (flags->hyphen == 1 && --flags->size >= len)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_pointer_null(t_param *flags)
{
	int	char_count;

	char_count = 0;
	if (flags->size <= 5)
		return (ft_putstr("(nil)"));
	while (flags->hyphen == 0 && --flags->size >= 5)
		char_count += ft_putchar(' ');
	char_count += ft_putstr("(nil)");
	while (flags->hyphen == 1 && --flags->size >= 5)
		char_count += ft_putchar(' ');
	return (char_count);
}
