/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:29:27 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 15:36:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_up(t_game *game)
{
	t_vect	new_pos;

	new_pos.x = pos_get_x(game) + dir_get_x(game) * game_m_speed(game);
	new_pos.y = pos_get_y(game) + dir_get_y(game) * game_m_speed(game);
	if (map_at(game, new_pos.x, new_pos.y) != WALL)
	{
		pos_set_x(game, new_pos.x);
		pos_set_y(game, new_pos.y);
	}
}

void	player_move_down(t_game *game)
{
	t_vect	new_pos;

	new_pos.x = pos_get_x(game) - dir_get_x(game) * game_m_speed(game);
	new_pos.y = pos_get_y(game) - dir_get_y(game) * game_m_speed(game);
	if (map_at(game, new_pos.x, new_pos.y) != WALL)
	{
		pos_set_x(game, new_pos.x);
		pos_set_y(game, new_pos.y);
	}
}

void	player_move_left(t_game *game)
{
	t_vect	new_pos;

	new_pos.x = pos_get_x(game) + -dir_get_y(game) * game_m_speed(game);
	new_pos.y = pos_get_y(game) + dir_get_x(game) * game_m_speed(game);
	if (map_at(game, new_pos.x, new_pos.y) != WALL)
	{
		pos_set_x(game, new_pos.x);
		pos_set_y(game, new_pos.y);
	}
}

void	player_move_right(t_game *game)
{
	t_vect	new_pos;

	new_pos.x = pos_get_x(game) - -dir_get_y(game) * game_m_speed(game);
	new_pos.y = pos_get_y(game) - dir_get_x(game) * game_m_speed(game);
	if (map_at(game, new_pos.x, new_pos.y) != WALL)
	{
		pos_set_x(game, new_pos.x);
		pos_set_y(game, new_pos.y);
	}
}
