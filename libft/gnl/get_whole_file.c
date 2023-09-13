/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:12:50 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/13 11:46:14 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_whole_file(int fd)
{
	char	*swap;
	char	*line;
	char	*whole_file;

	line = ft_get_next_line(fd);
	whole_file = ft_strdup("");
	while (line)
	{
		swap = whole_file;
		whole_file = ft_strjoin(whole_file, line);
		free(line);
		free(swap);
		line = ft_get_next_line(fd);
	}
	return (whole_file);
}