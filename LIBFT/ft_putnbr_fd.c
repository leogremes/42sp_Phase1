/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:47:28 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/03 22:27:51 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n < 0)
		write(fd, "-", 1);
	else if (n == 0)
		write(fd, "0", 1);
	else
		n *= -1;
	if (n <= -10)
	{
		ft_putnbr_fd((n / 10) * -1, fd);
		ft_putnbr_fd((n % 10) * -1, fd);
	}
	else if (n < 0)
	{
		digit = ((n % 10) * -1) + 48;
		write(fd, &digit, 1);
	}
}
