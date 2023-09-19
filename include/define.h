/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:26:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/18 23:24:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Map content type definition
# define EMPTY 2
# define FLOOR 0
# define WALL 1

// Map orientation definition
// ---
// North
# define NO 0
// South
# define SO 1
// Weast
# define WE 2
// East
# define EA 3

// Window definition
// ---
// Window width
# define WINDOW_W 620
// Window height
# define WINDOW_H 480
// Window title
# define WINDOW_T "Cub3D - Gabriel Souza & Renato Miranda"

// Minimap definition
// ---
// Mainimap Width
# define MMAP_W 100
// Minimap height
# define MMAP_H 100
// Player color on minimap
# define MMAP_PCOLOR 0x00FF9A03
// Wall color on minimap
# define MMAP_WCOLOR 0x00FFFFFF
// Floor color on minimap
# define MMAP_FCOLOR 0x00FFFFFF
// Minimap min and initial zoom
# define MMAP_MIN_ZOOM 2
// Minimap max zoom
# define MMAP_MAX_ZOOM 20

// Textures definition
// ---
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
// ---
// path_no: north texture path
// path_so: south texture path
// path_we: weast texture path
// path_ea: east texture pasth
// color_f: floor color
// color_c: ceiling color
// map: map matrix content
// m_height: map height
// m_width: map width
// orient: player orientation start (NO | SO | WE | EA)
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
// ---
// w: image width
// h: image height
// mlx: mlx data pointer
// data: image content buffer
// bpp: bit per pixel
// ls: line size
// path: image path
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
// mlx: mlx data pointer
// window: mlx window pointer
// screen: screen image buffer
// texture: array of textures
// info: configuration and map information structure
// pos: player position on map
// dir: player orientation direction
// fov: game field of view
// mmap_zoom: minimap current zoom
// mmap: minimap enable/disable
// rot_speed: rotation speed
// move_speed: movimentation speed
typedef struct s_game {
	void		*mlx;
	void		*window;
	t_img		screen;
	t_img		texture[4];
	t_map_info	info;
	t_vect		pos;
	t_vect		dir;
	double		fov;
	int			mmap_zoom;
	int			mmap;
	int			mouse_rot;
	double		rot_speed;
	double		move_speed;
}	t_game;

#endif