/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_unset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:29:27 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 03:24:41 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unset_player_move_up(t_game *game)
{
	game->runtime_action = game->runtime_action & ~MOVE_UP;
}

void	unset_player_move_down(t_game *game)
{
	game->runtime_action = game->runtime_action & ~MOVE_DOWN;
}

void	unset_player_move_left(t_game *game)
{
	game->runtime_action = game->runtime_action & ~MOVE_LEFT;
}

void	unset_player_move_right(t_game *game)
{
	game->runtime_action = game->runtime_action & ~MOVE_RIGHT;
}
