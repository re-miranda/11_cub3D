/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:55 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/18 19:50:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
