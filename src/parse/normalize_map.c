/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:49:49 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/23 23:58:16 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	assert_is_exposed_floor(t_map_info info, int xx, int yy);
static int	bounderies_check_vertical_axis(t_map_info info, int xx, int yy);
static int	bounderies_check_horizontal_axis(t_map_info info, int xx, int yy);

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
	int	yy;

	xx = 0;
	while (xx < info.m_height)
	{
		yy = 0;
		while (yy < info.m_width)
		{
			if (assert_is_exposed_floor(info, xx, yy))
				return (printf("Failed on map line %i char %i: ", ++xx, ++yy));
			yy++;
		}
		xx++;
	}
	return (0);
}

static int	assert_is_exposed_floor(t_map_info info, int xx, int yy)
{
	if (info.map[xx][yy] != FLOOR)
		return (0);
	if (bounderies_check_horizontal_axis(info, xx, yy))
		return (-1);
	if (bounderies_check_vertical_axis(info, xx, yy))
		return (-1);
	return (0);
}

static int	bounderies_check_vertical_axis(t_map_info info, int xx, int yy)
{
	int	index;

	index = xx;
	while (index--)
	{
		if (info.map[index][yy] == EMPTY)
			return (-1);
		if (info.map[index][yy] == WALL)
			break ;
	}
	if (index == -1 || info.map[index][yy] != WALL)
		return (-1);
	index = xx;
	while (++index < info.m_height)
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

static int	bounderies_check_horizontal_axis(t_map_info info, int xx, int yy)
{
	int	index;

	index = yy;
	while (index--)
	{
		if (info.map[xx][index] == EMPTY)
			return (-1);
		if (info.map[xx][index] == WALL)
			break ;
	}
	if (index == -1 || info.map[xx][index] != WALL)
		return (-1);
	index = yy;
	while (++index < info.m_width)
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
