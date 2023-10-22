/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:25:46 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/22 15:57:53 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#define ALLOWED_CHARACTERS " 01NWSE"

static int	lexical_analysis(char **map, int map_height);
static int	get_orient(t_map_info *info_ptr);

int	map_validation(t_map_info *info_ptr)
{
	int		index;

	index = 0;
	if (lexical_analysis(info_ptr->map, info_ptr->m_height))
		return (printf("Invalid character or empty line in map: "));
	if (get_orient(info_ptr) != 1)
		return (printf("More than one, or no orientation instruction in map: "));
	while (index < info_ptr->m_height)
	{
		if ((size_t)info_ptr->m_width < ft_strlen(info_ptr->map[index]))
			info_ptr->m_width = ft_strlen(info_ptr->map[index]);
		index++;
	}
	info_ptr->map = normalize_map(info_ptr);
	if (assert_is_not_surrounded_by_wall(info_ptr[0]))
		return (printf("Map must be surrounded by walls: "));
	return (0);
}

static void	space_injest_func(unsigned int nb, char *c)
{
	(void)nb;
	if (c[0] == ' ')
		c[0] = EMPTY;
	if (c[0] == '1')
		c[0] = WALL;
	if (c[0] == '0')
		c[0] = FLOOR;
}

char	**normalize_map(t_map_info *info_ptr)
{
	int		index;
	char	**temp;
	int		size;

	temp = ft_calloc(info_ptr->m_height + 1, sizeof(char **));
	index = 0;
	while (index < info_ptr->m_height)
	{
		temp[index] = ft_calloc(info_ptr->m_width + 1, sizeof(char));
		ft_memset(temp[index], EMPTY, info_ptr->m_width);
		size = ft_strlen(info_ptr->map[index]);
		ft_striteri(info_ptr->map[index], &space_injest_func);
		ft_memmove(temp[index], info_ptr->map[index], size);
		free(info_ptr->map[index]);
		index++;
	}
	free(info_ptr->map);
	return (temp);
}

int	assert_is_not_surrounded_by_wall(t_map_info info)
{
	int	xx;
	int yy;

	xx = 0;
	while (xx < info.m_height)
	{
		yy = 0;
		while (yy < info.m_width)
		{
			if(assert_is_exposed_floor(info, xx, yy))
				return (printf("Failed on map line %i char %i: ", ++xx, ++yy));
			yy++;
		}
		xx++;
	}
	return (0);
}

int	assert_is_exposed_floor(t_map_info info, int xx, int yy)
{
	if (info.map[xx][yy] != FLOOR)
		return (0);
	if (bounderies_check_horizontal_axis(info, xx, yy))
		return (-1);
	if (bounderies_check_vertical_axis(info, xx, yy))
		return (-1);
	return (0);

}

int	bounderies_check_vertical_axis(t_map_info info, int xx, int yy)
{
	int	index;

	index = xx;
	while  (index--)
	{
		if (info.map[index][yy] == EMPTY)
			return (-1);
		if (info.map[index][yy] == WALL)
			break ;
	}
	if (index == -1 || info.map[index][yy] != WALL)
		return (-1);
	index = xx;
	while  (++index < info.m_height)
	{
		if (info.map[index][yy] == EMPTY)
			return (-1);
		if (info.map[index][yy] == WALL)
			break ;
	}
	if (index == info.m_height)
		return (-1);
	return (0);
}

int	bounderies_check_horizontal_axis(t_map_info info, int xx, int yy)
{
	int	index;

	index = yy;
	while  (index--)
	{
		if (info.map[xx][index] == EMPTY)
			return (-1);
		if (info.map[xx][index] == WALL)
			break ;
	}
	if (index == -1 || info.map[xx][index] != WALL)
		return (-1);
	index = yy;
	while  (++index < info.m_width)
	{
		if (info.map[xx][index] == EMPTY)
			return (-1);
		if (info.map[xx][index] == WALL)
			break ;
	}
	if (index == info.m_width)
		return (-1);
	return (0);
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
	char	*map_line;
	int		xx;
	int		yy;
	int		return_value;

	xx = 0;
	return_value = 0;
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
