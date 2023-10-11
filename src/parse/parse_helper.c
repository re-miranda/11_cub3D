/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:27:17 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/11 11:49:07 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	add_path(char *line, char **dest);
static int	add_color(char *line, int *color_check, int *color);
static int	str_intrgb(char *line);

int	add_next_instruction(char *line, t_map_info *info_ptr)
{
	if (!ft_strncmp("NO ", line, 3))
	{
		if (add_path(ft_strdup(line + 3), &info_ptr->path_no))
			return (1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (add_path(ft_strdup(line + 3), &info_ptr->path_so))
			return (1);
	}
	else if (!ft_strncmp("WE ", line, 3))
	{
		if (add_path(ft_strdup(line + 3), &info_ptr->path_we))
			return (1);
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		if (add_path(ft_strdup(line + 3), &info_ptr->path_ea))
			return (1);
	}
	else if (!ft_strncmp("F ", line, 2))
	{
		if (add_color(line + 2, &info_ptr->color_f_check, &info_ptr->color_f))
			return (1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (add_color(line + 2, &info_ptr->color_c_check, &info_ptr->color_c))
			return (1);
	}
	return (0);
}

static int	add_path(char *line, char **dest)
{
	if (!line || dest[0])
		return (1);
	dest[0] = line;
	return (0);
}

int	add_line_to_map(t_map_info *info_ptr, char *line)
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

static int	add_color(char *line, int *color_check, int *color)
{
	if (color_check[0])
		return (1);
	color[0] = str_intrgb(line);
	color_check[0] = 1;
	return (0);
}

static int	str_intrgb(char *line)
{
	int	index;
	int	color_value;

	index = 16;
	color_value = 0;
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
