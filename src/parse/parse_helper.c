/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:27:17 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/13 11:42:51 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_helper(t_map_info *info_ptr, int map_fd)
{
	char	*line;

	line = ft_get_next_line(map_fd);
	printf("This is the fisrt line:\n%s", line);
	(void)info_ptr;
	if (line)
		free(line);
	return (0);
}
