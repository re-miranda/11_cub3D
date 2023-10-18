/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:55 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/17 21:39:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Map comment
*/
char	map_at(t_game *game, int x, int y)
{
	return (game->info.map[x][y]);
}

int	map_width(t_game *game)
{
	return (game->info.m_width);
}

int	map_height(t_game *game)
{
	return (game->info.m_height);
}
