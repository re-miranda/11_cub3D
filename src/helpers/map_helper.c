/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:55 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/19 10:03:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Map comment
*/
char	map_at(t_game *game, int x, int y)
{
	return (game->info.map[y][x]);
}

int	map_width(t_game *game)
{
	return (game->info.m_width);
}

int	map_height(t_game *game)
{
	return (game->info.m_height);
}
