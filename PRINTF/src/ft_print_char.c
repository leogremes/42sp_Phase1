/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:31:25 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/19 20:20:08 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_param *flags)
{
	int	char_count;

	char_count = 0;
	if (flags->size <= 0)
		return (ft_putchar(c));
	while (flags->hyphen == 0 && flags->size > 1)
	{
		char_count += ft_putchar(' ');
		flags->size--;
	}
	char_count += ft_putchar(c);
	while (flags->hyphen == 1 && flags->size > 1)
	{
		char_count += ft_putchar(' ');
		flags->size--;
	}
	return (char_count);
}
