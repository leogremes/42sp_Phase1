/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:47:21 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/19 20:19:55 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_symbol_flags(char c, t_param *parameters);

t_param	*init_flags(void)
{
	t_param	*parameters;

	parameters = (t_param *)malloc(sizeof(t_param));
	if (!parameters)
		return (NULL);
	parameters->hyphen = 0;
	parameters->zero = 0;
	parameters->dot = 0;
	parameters->sharp = 0;
	parameters->space = 0;
	parameters->plus = 0;
	parameters->size = 0;
	parameters->width = 0;
	parameters->type = 0;
	return (parameters);
}

void	get_flags(const char *text, t_param *parameters)
{
	while (text[0] != '\0' && (text[0] < '1' || text[0] > '9')
		&& ft_is_data_type_char(text[0]) == 0 && text[0] != '.')
	{
		get_symbol_flags(text[0], parameters);
		text++;
	}
	while (text[0] >= '0' && text[0] <= '9')
	{
		parameters->size = (parameters->size * 10) + (text[0] - '0');
		text++;
	}
	if (text[0] == '.')
	{
		parameters->dot = 1;
		text++;
	}
	while (text[0] >= '0' && text[0] <= '9')
	{
		parameters->width = (parameters->width * 10) + (text[0] - '0');
		text++;
	}
	parameters->type = text[0];
}

static void	get_symbol_flags(char c, t_param *parameters)
{
	if (c == '-')
		parameters->hyphen = 1;
	if (c == '0')
		parameters->zero = 1;
	if (c == '#')
		parameters->sharp = 1;
	if (c == ' ')
		parameters->space = 1;
	if (c == '+')
		parameters->plus = 1;
}
