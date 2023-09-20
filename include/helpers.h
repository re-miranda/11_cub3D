/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:25:07 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 17:00:24 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "cub3d.h"

// Game config helpers
//
// Get game 'move speed' configuration
double	game_m_speed(t_game *game);
// Get game 'rotation speed' configuration
double	game_r_speed(t_game *game);
// Get game 'ceiling color' configuration
int		game_c_color(t_game *game);
// Get game 'floor color' configuration
int		game_f_color(t_game *game);

// Map helpers
//
// Get map element at 'x,y' position
char	map_at(t_game *game, int x, int y);
// Get map width
int		map_width(t_game *game);
// Get map height
int		map_height(t_game *game);

// Player positon helpers
//
// Get player 'x' positon
double	pos_get_x(t_game *game);
// Get player 'y' positon
double	pos_get_y(t_game *game);
// Set player 'x' positon
void	pos_set_x(t_game *game, double x);
// Set player 'y' positon
void	pos_set_y(t_game *game, double y);

// Player direction helpers
//
// Get player 'x' direction
double	dir_get_x(t_game *game);
// Get player 'y' direction
double	dir_get_y(t_game *game);
// Set player 'x' direction
void	dir_set_x(t_game *game, double x);
// Set player 'y' direction
void	dir_set_y(t_game *game, double y);

// Player field of view helpers
//
// Get player 'x' field of view
double	fov_get_x(t_game *game);
// Get player 'y' field of view
double	fov_get_y(t_game *game);
// Set player 'x' field of view
void	fov_set_x(t_game *game, double x);
// Set player 'y' field of view
void	fov_set_y(t_game *game, double y);

// Image helpers
//
// Get image integer color at x,y position
int		img_get_color_at(t_img *img, int x, int y);
// Get image pixel data address at x,y position
char	*img_get_pixel_at(t_img *img, int x, int y);

#endif
