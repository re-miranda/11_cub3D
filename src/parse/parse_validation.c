/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:25:46 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/11 11:06:23 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#define ALLOWED_CHARACTERS " 01NWSE"

static int	lexical_analysis(char **map, int map_height);
static int	get_orient(t_map_info *info_ptr);
// static int	find_unclosed_wall(char **map);

int	map_validation(t_map_info *info_ptr)
{
	int		index;

	index = 0;
	if (lexical_analysis(info_ptr->map, info_ptr->m_height))
		return (printf("Invalid character or empty line in map: "));
	if (get_orient(info_ptr) != 1)
		return (printf("More than one orientation instruction in map: "));
	while (index < info_ptr->m_height)
	{
		if ((size_t)info_ptr->m_width < ft_strlen(info_ptr->map[index]))
			info_ptr->m_width = ft_strlen(info_ptr->map[index]);
		index++;
	}
	info_ptr->map = normalize_map(info_ptr);
	// if (find_unclosed_wall(info_ptr->map))
	// 	return (printf("Unclosed room in map: "));
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

// static int	find_unclosed_wall(char **map)
// {
// 	int	xx;
// 	int yy;

// 	xx = 0;
// 	yy = 0;
// 	while (map[xx][yy])
// 	{
// 		if (!map[xx][yy + 2])
// 		{
// 			if (!map[xx + 2])
// 				break ;
// 			yy = 0;
// 			continue ;
// 		}
// 	}
// }

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
		map_line = info_ptr->map[xx++];
		yy = 0;
		while (map_line[yy])
		{
			if (ft_isalpha(map_line[yy]))
			{
				info_ptr->pos.y = yy;
				info_ptr->pos.x = xx;
				info_ptr->orient = map_line[yy];
 				map_line[yy] = '0';
				return_value++;
			}
			yy++;
		}
	}
	return (return_value);
}
