/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:51:27 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 17:01:28 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

// Movements and rotations
//
// Move player to up
void	player_move_up(t_game *game);
// Move player to down
void	player_move_down(t_game *game);
// Move player to left
void	player_move_left(t_game *game);
// Move player to right
void	player_move_right(t_game *game);
// Rotate field of view to left
void	fov_rotate_left(t_game *game);
// Rotate field of view to right
void	fov_rotate_right(t_game *game);

// Game general functions
//
// Load game textures configured at t_map_info
// @exception Don't destroy mlx images when errors occur
// @return 1 when success and 0 when fail to load any image
int		game_textures_load(t_game *game);
// Destroy mlx images from textures array
void	game_textures_destroy(t_game *game);
// Setup game default values, mlx configuration and screen image buffer
int		game_setup(t_game *game);

#endif