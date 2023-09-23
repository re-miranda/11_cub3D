/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:37 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 15:47:09 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>

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
	if (key == XK_Escape || key == XK_q)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	return (0);
}

static void	player_movement(int key, t_game *game)
{
	if (key == XK_w)
		player_move_up(game);
	if (key == XK_s)
		player_move_down(game);
	if (key == XK_a)
		player_move_left(game);
	if (key == XK_d)
		player_move_right(game);
}

static void	fov_rotation(int key, t_game *game)
{
	if (key == XK_Right)
		fov_rotate_right(game);
	if (key == XK_Left)
		fov_rotate_left(game);
}

static void	minimap_toggle(int key, t_game *game)
{
	if (key == XK_m)
		game->mmap = !game->mmap;
}
