/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:27:17 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/17 01:54:44 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#define SKIP_NEWLINE 1
#define KEEP_NEWLINE 0
#define C 1
#define F 0

static char	*get_next_line(int fd, int skip_nl);
static int	add_line_to_map(t_map_info *info_ptr, char *line);
static int	str_to_int_rgb(char *line, int flag_floor_or_ceiling);

int	parse_helper(t_map_info *info_ptr, int map_fd)
{
	info_ptr->path_no = ft_strdup(get_next_line(map_fd, SKIP_NEWLINE));
	info_ptr->path_so = ft_strdup(get_next_line(map_fd, SKIP_NEWLINE));
	info_ptr->path_we = ft_strdup(get_next_line(map_fd, SKIP_NEWLINE));
	info_ptr->path_ea = ft_strdup(get_next_line(map_fd, SKIP_NEWLINE));
	info_ptr->color_f = str_to_int_rgb(get_next_line(map_fd, SKIP_NEWLINE), F);
	info_ptr->color_c = str_to_int_rgb(get_next_line(map_fd, SKIP_NEWLINE), C);
	add_line_to_map(info_ptr, get_next_line(map_fd, SKIP_NEWLINE));
	while (!add_line_to_map(info_ptr, get_next_line(map_fd, KEEP_NEWLINE)))
		;
	while (get_next_line(map_fd, KEEP_NEWLINE))
			;
	return (0);
}

static char	*get_next_line(int fd, int skip_nl)
{
	static char	*line;

	if (line)
		free(line);
	line = ft_get_next_line(fd);
	while (skip_nl && !ft_strncmp(line, "\n", 3))
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	return (line);
}

static int	add_line_to_map(t_map_info *info_ptr, char *line)
{
	char	**swap;
	int		new_size;

	swap = info_ptr->map;
	new_size = info_ptr->m_height + 1;
	if (!line)
		return (1);
	info_ptr->map = ft_calloc(new_size, sizeof(char *));
	ft_memmove(info_ptr->map, swap, (new_size - 1) * sizeof(char *));
	if (swap)
		free(swap);
	info_ptr->map[new_size - 1] = ft_strdup(line);
	info_ptr->m_height = new_size;
	return (0);
}

static int	str_to_int_rgb(char *line, int flag__floor_or_ceiling)
{
	int	index;
	int	color_value;

	index = 16;
	color_value = 0;
	if ((flag__floor_or_ceiling == F
			&& !ft_strncmp(line, "F ", 2))
		&& (flag__floor_or_ceiling == C
			&& !ft_strncmp(line, "C ", 2)))
		return (0xff000000);
	line += 2;
	while (index)
	{
		color_value = ((ft_atoi(line) << index) | color_value);
		while (ft_isdigit(line[0]))
			line++;
		line++;
		index -= 8;
	}
	color_value = ((ft_atoi(line)) | color_value);
	return (color_value);
}
