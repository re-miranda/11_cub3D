/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:51:53 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/19 10:31:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dir_get_x(t_game *game)
{
	return (game->dir.x);
}

double	dir_get_y(t_game *game)
{
	return (game->dir.y);
}

void	dir_set_x(t_game *game, double x)
{
	game->dir.x = x;
}

void	dir_set_y(t_game *game, double y)
{
	game->dir.y = y;
}
