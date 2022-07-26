/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:45:22 by leda-sil          #+#    #+#             */
/*   Updated: 2022/07/25 13:51:40 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_param
{
	int	hyphen;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	size;
	int	width;
	int	type;
}		t_param;

int		ft_printf(const char *text, ...);
t_param	*init_flags(void);
void	get_flags(const char *text, t_param *parameters);
int		print_char(char c, t_param *flags);
int		print_string(char *str, t_param *flags);
int		print_integer(int num, t_param *flags);
int		print_unsigned(unsigned int num, t_param *flags);
int		print_hexadecimal(unsigned int num, t_param *flags);
int		print_pointer(void *ptr, t_param *flags);
int		print_zero_no_width(t_param *flags);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putstr_partial(char *s, int len);
int		ft_putnbr_abs(int num, int base, int upper);
int		ft_putnbr_uns(unsigned int num, unsigned int base, int upper);
int		ft_putnbr_long(unsigned long num, unsigned int base, int upper);
int		ft_strlen(char *s);
int		ft_nbrlen_abs(int num, int base);
int		ft_nbrlen_uns(unsigned int num, unsigned int base);
int		ft_nbrlen_long(unsigned long num, unsigned int base);
int		ft_is_data_type_char(char c);

#endif