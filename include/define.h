/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:26:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/22 21:36:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Map elements type definition
//
// Empty map element
# define EMPTY 2
// Floor map element
# define FLOOR 0
// Wall map element
# define WALL 1

// Map orientation definition
//
// North
# define NO 0
// South
# define SO 1
// Weast
# define WE 2
// East
# define EA 3

// Mouse buttons number definition
//
// Mouse scroll up button number
# define MOUSE_SCROLL_UP 4
// Mouse scroll down button number
# define MOUSE_SCROLL_DOWN 5

// Window definition
//
// Window width
# define WINDOW_W 620
// Window height
# define WINDOW_H 480
// Window title
# define WINDOW_T "Cub3D - Gabriel Souza & Renato Miranda"

// Minimap definition
//
// Mainimap width
# define MMAP_W 100
// Minimap height
# define MMAP_H 100
// Player color on minimap
# define MMAP_PCOLOR 0x00FF9A03
// Wall color on minimap
# define MMAP_WCOLOR 0x00FFFFFF
// Floor color on minimap
# define MMAP_FCOLOR 0x00FFFFFF
// Minimap min zoom (and initial zoom)
# define MMAP_MIN_ZOOM 2
// Minimap max zoom
# define MMAP_MAX_ZOOM 20

// Textures definition
//
// Texture width
# define TEXTURE_W 64
// Texture height
# define TEXTURE_H 64

// Vector with 'double' x and y coordinates
typedef struct s_vect {
	double	x;
	double	y;
}	t_vect;

// Vector with 'integer' x and y coordinates
typedef struct s_ivect {
	int	x;
	int	y;
}	t_ivect;

// Map information structure
//
// @param *path_no north texture path
// @param *path_so south texture path
// @param *path_we weast texture path
// @param *path_ea east texture pasth
// @param color_f floor color
// @param color_c ceiling color
// @param **map map matrix content
// @param m_height map height
// @param m_width map width
// @param orient player initial orientation (NO | SO | WE | EA)
typedef struct s_map_info {
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		color_f;
	int		color_c;
	char	**map;
	int		m_height;
	int		m_width;
	char	orient;
	t_vect	pos;
}	t_map_info;

// Image information structure
//
// @param w image width
// @param h image height
// @param *mlx mlx data pointer
// @param *data image content buffer
// @param bpp bit per pixel
// @param ls line size
// @param *path image path
typedef struct s_img {
	int		w;
	int		h;
	void	*mlx;
	char	*data;
	int		bpp;
	int		end;
	int		ls;
	char	*path;
}	t_img;

// Game information structure
//
// @param *mlx mlx data pointer
// @param *window mlx window pointer
// @param screen screen image buffer
// @param texture[4] array of textures
// @param info configuration and map information structure
// @param pos player position on map
// @param dir player orientation direction
// @param fov game field of view
// @param mmap_zoom minimap current zoom
// @param mmap minimap enable/disable
// @param rot_speed rotation speed
// @param move_speed movimentation speed
typedef struct s_game {
	void		*mlx;
	void		*window;
	t_img		screen;
	t_img		texture[4];
	t_map_info	info;
	t_vect		pos;
	t_vect		dir;
	t_vect		fov;
	int			mmap_zoom;
	int			mmap;
	int			mouse_rot;
	double		rot_speed;
	double		move_speed;
}	t_game;

// Raycasting information structure
//
// @param ray_dir ray direction vector
// @param delta_dist length of ray from one x or y-side to next x or y-side
// @param side_dist length of ray from current position to next x or y-side
// @param step what direction to step in x or y-direction (either +1 or -1)
// @param pos which position of the map we're in
// @param side was a NS or a EW wall hit? (1 NS and 0 EW)
// @param orient which orientation wall was hit (NO, SO, WE, EA)
// @param perp_wall_dist perpendicular wall distance
// @param wall_x_hit where exactly the wall was hit
// @param wall_line_h wall lenght to drawn on screen
// @param wall_draw_start height on the screen will the wall start to be drawn
// @param wall_draw_end height on the screen will the wall stop to be drawn
// @param rate proportion (new scale) of the texture to be drawn
typedef struct s_raycast {
	t_vect	ray_dir;
	t_vect	delta_dist;
	t_vect	side_dist;
	t_ivect	step;
	t_ivect	pos;
	int		side;
	int		orient;
	double	perp_wall_dist;
	double	wall_x_hit;
	int		wall_line_h;
	int		wall_draw_start;
	int		wall_draw_end;
	double	rate;
}	t_raycast;

#endif