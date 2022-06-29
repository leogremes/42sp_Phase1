/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:52:25 by leda-sil          #+#    #+#             */
/*   Updated: 2022/06/27 20:26:38 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_strseek(char *str, char c);
char	*ft_strjoin(char *first, char *last);
t_list	*ft_lstnew(int file_d);

#endif
