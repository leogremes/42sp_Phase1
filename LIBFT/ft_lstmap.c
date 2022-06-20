/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:03:58 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/07 21:06:12 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	ret = ft_lstnew(f(lst->content));
	if (ret)
	{
		while (lst->next)
		{
			lst = lst->next;
			temp = ft_lstnew(f(lst->content));
			if (!temp)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, temp);
		}
	}
	return (ret);
}
