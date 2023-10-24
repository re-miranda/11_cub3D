/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:25:46 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/23 21:35:06 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	lexical_analysis(char **map, int map_height);
static int	get_orient(t_map_info *info_ptr);

int	map_validation(t_map_info *info_ptr)
{
	int		index;

	index = 0;
	if (lexical_analysis(info_ptr->map, info_ptr->m_height))
		return (1);
	if (get_orient(info_ptr) != 1)
		return (1);
	while (index < info_ptr->m_height)
	{
		if ((size_t)info_ptr->m_width < ft_strlen(info_ptr->map[index]))
			info_ptr->m_width = ft_strlen(info_ptr->map[index]);
		index++;
	}
	info_ptr->map = normalize_map(info_ptr);
	if (assert_is_not_surrounded_by_wall(info_ptr[0]))
		return (1);
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

void	space_injest_func(unsigned int nb, char *c)
{
	(void)nb;
	if (c[0] == ' ')
		c[0] = EMPTY;
	if (c[0] == '1')
		c[0] = WALL;
	if (c[0] == '0')
		c[0] = FLOOR;
}

static int	lexical_analysis(char **map, int map_height)
{
	char	*map_line;
	int		index;

	index = 0;
	while (index < map_height)
	{
		map_line = map[index++];
		while (map_line[0] == ' ')
			map_line++;
		if (!map_line[0])
			return (1);
		while (map_line[0] && ft_strchr(ALLOWED_CHARACTERS, map_line[0]))
			map_line++;
		if (map_line[0])
			return (1);
	}
	return (0);
}

static int	get_orient(t_map_info *info_ptr)
{
	char		*map_line;
	int			xx;
	int			yy;
	static int	return_value = 0;

	xx = 0;
	while (xx < info_ptr->m_height)
	{
		map_line = info_ptr->map[xx];
		yy = 0;
		while (map_line[yy])
		{
			if (ft_isalpha(map_line[yy]))
			{
				info_ptr->pos.y = yy + 0.5;
				info_ptr->pos.x = xx + 0.5;
				info_ptr->orient = map_line[yy];
				map_line[yy] = '0';
				return_value++;
			}
			yy++;
		}
		xx++;
	}
	return (return_value);
}
