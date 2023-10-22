/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_listener.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:37 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 01:29:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_movement(int key, t_game *game);
static void	fov_rotation(int key, t_game *game);

int	key_release_listener(int key, t_game *game)
{
	player_movement(key, game);
	fov_rotation(key, game);
	return (0);
}

static void	player_movement(int key, t_game *game)
{
	if (key == KEY_W)
		unset_player_move_up(game);
	if (key == KEY_S)
		unset_player_move_down(game);
	if (key == KEY_A)
		unset_player_move_left(game);
	if (key == KEY_D)
		unset_player_move_right(game);
}

static void	fov_rotation(int key, t_game *game)
{
	if (key == KEY_ARROW_RIGHT)
		unset_fov_rotate_right(game);
	if (key == KEY_ARROW_LEFT)
		unset_fov_rotate_left(game);
}
