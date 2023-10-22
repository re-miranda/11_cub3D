/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_listener.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:37 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 17:31:18 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_movement(int key, t_game *game);
static void	fov_rotation(int key, t_game *game);
static void	minimap_toggle(int key, t_game *game);
static int	game_close(int key, t_game *game);

int	key_press_listener(int key, t_game *game)
{
	if (!game_close(key, game))
	{
		player_movement(key, game);
		fov_rotation(key, game);
		minimap_toggle(key, game);
	}
	render_the_screen(game);
	return (0);
}

static int	game_close(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	return (0);
}

static void	player_movement(int key, t_game *game)
{
	if (key == KEY_W)
		set_player_move_up(game);
	if (key == KEY_S)
		set_player_move_down(game);
	if (key == KEY_A)
		set_player_move_left(game);
	if (key == KEY_D)
		set_player_move_right(game);
	if (game->runtime_action & MOVE_UP)
		player_move_up(game);
	if (game->runtime_action & MOVE_DOWN)
		player_move_down(game);
	if (game->runtime_action & MOVE_LEFT)
		player_move_left(game);
	if (game->runtime_action & MOVE_RIGHT)
		player_move_right(game);
}

static void	fov_rotation(int key, t_game *game)
{
	if (key == KEY_ARROW_RIGHT)
		set_fov_rotate_right(game);
	if (key == KEY_ARROW_LEFT)
		set_fov_rotate_left(game);
	if (game->runtime_action & LOOK_RIGHT)
		fov_rotate_right(game);
	if (game->runtime_action & LOOK_LEFT)
		fov_rotate_left(game);
}

static void	minimap_toggle(int key, t_game *game)
{
	if (key == KEY_M)
		game->mmap = !game->mmap;
}
