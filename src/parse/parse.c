/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:23:34 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/11 11:49:49 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	abort_handler(t_map_info info);
static int	parse_getter(t_map_info *info_ptr, int map_fd);
static char	*get_nl(int fd, int skip_nl);
static int	assert_completeness(t_map_info info);

int	parse(t_map_info *info_ptr, char *map_path)
{
	int	success_flag;
	int	fd;

	success_flag = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		success_flag = printf("Failed to open file: ");
	ft_memset(info_ptr, 0, sizeof(t_map_info));
	if (!success_flag && parse_getter(info_ptr, fd))
		success_flag = printf("Failed to load parser: ");
	close(fd);
	// if (!success_flag && textures_validation(info_ptr))
	// 	success_flag = printf("Failed to validate textures: ");
	if (!success_flag && map_validation(info_ptr))
		success_flag = printf("Failed to validate map: ");
	if (success_flag)
		abort_handler(*info_ptr);
	return (success_flag);
}

static void	abort_handler(t_map_info info)
{
	printf("Aborting operation: ");
	if (info.path_ea)
		free(info.path_ea);
	if (info.path_no)
		free(info.path_no);
	if (info.path_so)
		free(info.path_so);
	if (info.path_we)
		free(info.path_we);
	if (info.map)
	{
		while (info.m_height--)
			free(info.map[info.m_height]);
		free(info.map);
	}
}

static int	parse_getter(t_map_info *info_ptr, int map_fd)
{
	char	*line;
	int		error_flag;

	error_flag = 0;
	while (!error_flag && assert_completeness(info_ptr[0]))
	{
		line = get_nl(map_fd, SKIP_NL);
		if (add_next_instruction(line, info_ptr))
			error_flag = 1;
	}
	if (!error_flag)
	{
		add_line_to_map(info_ptr, get_nl(map_fd, SKIP_NL));
		while (!add_line_to_map(info_ptr, get_nl(map_fd, KEEP_NEWLINE)))
			;
	}
	while (get_nl(map_fd, KEEP_NEWLINE))
		;
	return (error_flag);
}


static char	*get_nl(int fd, int skip_nl)
{
	static char	*line;

	if (line)
		free(line);
	line = ft_get_next_line(fd);
	while (line && skip_nl && !ft_strncmp(line, "\n", 3))
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	return (line);
}

static int	assert_completeness(t_map_info info)
{
	if (!info.path_no)
		return (1);
	if (!info.path_so)
		return (1);
	if (!info.path_we)
		return (1);
	if (!info.path_ea)
		return (1);
	if (!info.color_f_check)
		return (1);
	if (!info.color_c_check)
		return (1);
	return (0);
}
