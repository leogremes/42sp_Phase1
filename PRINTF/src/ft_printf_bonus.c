/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:27:33 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 14:09:24 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_data(const char *text, va_list data);
static int	conversion(t_param *flags, va_list data);

int	ft_printf(const char *text, ...)
{
	int		char_count;
	va_list	data;

	char_count = 0;
	va_start(data, text);
	if (text)
	{
		while (text[0] != '\0')
		{
			if (text[0] != '%')
				char_count += ft_putchar(text[0]);
			else
			{
				char_count += print_data(text, data);
				text++;
				while (ft_is_data_type_char(text[0]) == 0 && text[0] != '\0')
					text++;
			}
			if (text[0] != '\0')
				text++;
		}
	}
	va_end(data);
	return (char_count);
}

static int	print_data(const char *text, va_list data)
{
	t_param	*flags;
	int		char_count;

	char_count = 0;
	flags = init_flags();
	text++;
	get_flags(text, flags);
	char_count = conversion(flags, data);
	free(flags);
	return (char_count);
}

static int	conversion(t_param *flags, va_list data)
{
	if (flags->type == 'c')
		return (print_char(va_arg(data, int), flags));
	if (flags->type == 's')
		return (print_string(va_arg(data, char *), flags));
	if (flags->type == 'p')
		return (print_pointer(va_arg(data, void *), flags));
	if (flags->type == 'd')
		return (print_integer(va_arg(data, int), flags));
	if (flags->type == 'i')
		return (print_integer(va_arg(data, int), flags));
	if (flags->type == 'u')
		return (print_unsigned(va_arg(data, int), flags));
	if (flags->type == 'x')
		return (print_hexadecimal(va_arg(data, int), flags));
	if (flags->type == 'X')
		return (print_hexadecimal(va_arg(data, int), flags));
	if (flags->type == '%')
		return (ft_putchar('%'));
	return (0);
}
