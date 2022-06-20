/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:33:11 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/06 22:06:12 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && del)
	{
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), del);
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}
