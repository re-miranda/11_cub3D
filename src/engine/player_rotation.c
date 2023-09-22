/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:01:18 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 15:56:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fov_rotate_left(t_game *game)
{
	t_vect	dir;
	t_vect	fov;
	double	speed;

	speed = game_r_speed(game);
	dir.x = dir_get_x(game);
	dir.y = dir_get_y(game);
	dir_set_x(game, dir.x * cos(speed) - dir.y * sin(speed));
	dir_set_y(game, dir.x * sin(speed) + dir.y * cos(-speed));
	fov.x = fov_get_x(game);
	fov.y = fov_get_y(game);
	fov_set_x(game, fov.x * cos(speed) - fov.y * sin(speed));
	fov_set_y(game, fov.x * sin(speed) + fov.y * cos(speed));
}

void	fov_rotate_right(t_game *game)
{
	t_vect	dir;
	t_vect	fov;
	double	speed;

	speed = game_r_speed(game);
	dir.x = dir_get_x(game);
	dir.y = dir_get_y(game);
	dir_set_x(game, dir.x * cos(-speed) - dir.y * sin(-speed));
	dir_set_y(game, dir.x * sin(-speed) + dir.y * cos(-speed));
	fov.x = fov_get_x(game);
	fov.y = fov_get_y(game);
	fov_set_x(game, fov.x * cos(-speed) - fov.y * sin(-speed));
	fov_set_y(game, fov.x * sin(-speed) + fov.y * cos(-speed));
}
