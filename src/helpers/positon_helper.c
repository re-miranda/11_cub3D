/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positon_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:48:01 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/19 10:31:16 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pos_get_x(t_game *game)
{
	return (game->pos.x);
}

double	pos_get_y(t_game *game)
{
	return (game->pos.y);
}

void	pos_set_x(t_game *game, double x)
{
	game->pos.x = x;
}

void	pos_set_y(t_game *game, double y)
{
	game->pos.y = y;
}
