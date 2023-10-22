/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:51:27 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 17:38:22 by rmiranda         ###   ########.fr       */
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
// Set / Unset move player to up
void	set_player_move_up(t_game *game);
void	unset_player_move_up(t_game *game);
// Set / Unset move player to down
void	set_player_move_down(t_game *game);
void	unset_player_move_down(t_game *game);
// Set / Unset move player to left
void	set_player_move_left(t_game *game);
void	unset_player_move_left(t_game *game);
// Set / Unset move player to right
void	set_player_move_right(t_game *game);
void	unset_player_move_right(t_game *game);
// Set / Unset motate field of view to left
void	set_fov_rotate_left(t_game *game);
void	unset_fov_rotate_left(t_game *game);
// Set / Unset motate field of view to right
void	set_fov_rotate_right(t_game *game);
void	unset_fov_rotate_right(t_game *game);

// Game general functions
//
// @exception Don't destroy mlx images when errors occur
// @return 1 when success and 0 when fail to load any image
int		game_textures_load(t_game *game);
// Destroy mlx images from textures array
void	game_textures_destroy(t_game *game);
// Setup game default values, mlx configuration and screen image buffer
int		game_setup(t_game *game);
// Destroy game screen buffer image, window, display and mlx
void	game_destroy(t_game *game);
// Perform keys listener
int		key_press_listener(int key, t_game *game);
int		key_release_listener(int key, t_game *game);
// Perform mouse listener
int		mouse_listener(int button, int x, int y, t_game *game);
// Render the game screen with your current status
void	render_the_screen(t_game *game);
// Display minimap on screen
void	display_minimap(t_game *game);
// Display player direction on screen
void display_direction(t_game *game);

// Raycasting
//
// Perform raycasting
void	raycasting(t_game *game);
// Perform DDA (Digital Differential Analyzer) algorithm
void	calculate_dda(t_game *game, t_raycast *rc);
// Calculate the ray direction on current screen column
void	calculate_ray_direction(t_game *game, t_raycast *rc, int screen_col);
// Calculate the lenght of the ray
void	calculate_delta_distance(t_raycast *rc);
// Calculate step and side distance
void	calculate_step_and_side_dist(t_game *game, t_raycast *rc);
// Calculate perpendicular wall distance
void	calculate_perpendicular_wall_distance(t_raycast *rc);
// Calculate where exactly the wall was hit
void	calculate_where_wall_was_hit(t_game *game, t_raycast *rc);
// Draw current raycasting screen column
void	draw_screen_column(t_game *game, t_raycast *rc, int screen_column);

#endif