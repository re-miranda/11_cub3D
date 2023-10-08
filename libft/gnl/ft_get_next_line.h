/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:37:09 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/08 06:32:09 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 10

typedef struct s_list
{
	int				fd;
	char			*buffer;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

char	*ft_get_next_line(int fd);
char	*ft_strdup_gnl(char *str);
t_list	*new_node(int fd, t_list *previous);

#endif