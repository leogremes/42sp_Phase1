/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:16:45 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:11 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_string_null(t_param *flags);

int	print_string(char *str, t_param *flags)
{
	int	len;
	int	char_count;

	if (!str)
		return (print_string_null(flags));
	len = 0;
	char_count = 0;
	while (str[len] != '\0' && !(flags->dot == 1 && len >= flags->width))
		len++;
	if (flags->size <= len)
		return (ft_putstr_partial(str, len));
	while (flags->hyphen == 0 && --flags->size >= len)
		char_count += ft_putchar(' ');
	char_count += ft_putstr_partial(str, len);
	while (flags->hyphen == 1 && --flags->size >= len)
		char_count += ft_putchar(' ');
	return (char_count);
}

static int	print_string_null(t_param *flags)
{
	int	char_count;
	int	len;

	char_count = 0;
	if (flags->dot == 1 && flags->width < 6)
		len = 0;
	else
		len = 6;
	if (flags->size <= len)
		return (ft_putstr_partial("(null)", len));
	while (flags->hyphen == 0 && --flags->size >= len)
		char_count += ft_putchar(' ');
	char_count += ft_putstr_partial("(null)", len);
	while (flags->hyphen == 1 && --flags->size >= len)
		char_count += ft_putchar(' ');
	return (char_count);
}
