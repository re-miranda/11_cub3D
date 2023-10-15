/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:37 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/15 18:51:06 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_movement(int key, t_game *game);
static void	fov_rotation(int key, t_game *game);
static void	minimap_toggle(int key, t_game *game);
static int	game_close(int key, t_game *game);

int	key_listener(int key, t_game *game)
{
	if (!game_close(key, game))
	{
		player_movement(key, game);
		fov_rotation(key, game);
		minimap_toggle(key, game);
		render_the_screen(game);
	}
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
		player_move_up(game);
	if (key == KEY_S)
		player_move_down(game);
	if (key == KEY_A)
		player_move_left(game);
	if (key == KEY_D)
		player_move_right(game);
}

static void	fov_rotation(int key, t_game *game)
{
	if (key == KEY_ARROW_RIGHT)
		fov_rotate_right(game);
	if (key == KEY_ARROW_LEFT)
		fov_rotate_left(game);
}

static void	minimap_toggle(int key, t_game *game)
{
	if (key == KEY_M)
		game->mmap = !game->mmap;
}
