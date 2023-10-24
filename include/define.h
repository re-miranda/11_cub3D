/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:26:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/23 22:00:03 by rmiranda         ###   ########.fr       */
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

// Game Speed
//
// Movement speed
# define MOV_SPEED 0.02
// Field of view rotation speed
# define ROT_SPEED 0.02

// Key Maps definition

# define KEY_ESC 0xff1b
# define KEY_A 0x0061
# define KEY_W 0x0077
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_Q 0x0071
# define KEY_M 0x006d
# define KEY_ARROW_LEFT 0xff51 
# define KEY_ARROW_RIGHT 0xff53

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
# define MMAP_W 150
// Minimap height
# define MMAP_H 150
// Player color on minimap
# define MMAP_PCOLOR 0x00FF9A03
// Wall color on minimap
# define MMAP_WCOLOR 0x00FFFFFF
// Floor color on minimap
# define MMAP_FCOLOR 0x00
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
	int		color_f_check;
	int		color_f;
	int		color_c_check;
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

/***************************************************************** 
 * X11 EVENT DEFINITIONS 
 *****************************************************************/

/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests.  Not to be confused with event names.  */

// # define NoEventMask			0L
// # define KeyPressMask			(1L<<0)
// # define KeyReleaseMask			(1L<<1)
// # define ButtonPressMask			(1L<<2)
// # define ButtonReleaseMask		(1L<<3)
// # define EnterWindowMask			(1L<<4)
// # define LeaveWindowMask			(1L<<5)
// # define PointerMotionMask		(1L<<6)
// # define PointerMotionHintMask		(1L<<7)
// # define Button1MotionMask		(1L<<8)
// # define Button2MotionMask		(1L<<9)
// # define Button3MotionMask		(1L<<10)
// # define Button4MotionMask		(1L<<11)
// # define Button5MotionMask		(1L<<12)
// # define ButtonMotionMask		(1L<<13)
// # define KeymapStateMask			(1L<<14)
// # define ExposureMask			(1L<<15)
// # define VisibilityChangeMask		(1L<<16)
// # define StructureNotifyMask		(1L<<17)
// # define ResizeRedirectMask		(1L<<18)
// # define SubstructureNotifyMask		(1L<<19)
// # define SubstructureRedirectMask	(1L<<20)
// # define FocusChangeMask			(1L<<21)
// # define PropertyChangeMask		(1L<<22)
// # define ColormapChangeMask		(1L<<23)
// # define OwnerGrabButtonMask		(1L<<24)

// /* Event names.  Used in "type" field in XEvent structures.  Not to be
// confused with event masks above.  They start from 2 because 0 and 1
// are reserved in the protocol for errors and replies. */

// # define KeyPress		2
// # define KeyRelease		3
// # define ButtonPress		4
// # define ButtonRelease		5
// # define MotionNotify		6
// # define EnterNotify		7
// # define LeaveNotify		8
// # define FocusIn			9
// # define FocusOut		10
// # define KeymapNotify		11
// # define Expose			12
// # define GraphicsExpose		13
// # define NoExpose		14
// # define VisibilityNotify	15
// # define CreateNotify		16
// # define DestroyNotify		17
// # define UnmapNotify		18
// # define MapNotify		19
// # define MapRequest		20
// # define ReparentNotify		21
// # define ConfigureNotify		22
// # define ConfigureRequest	23
// # define GravityNotify		24
// # define ResizeRequest		25
// # define CirculateNotify		26
// # define CirculateRequest	27
// # define PropertyNotify		28
// # define SelectionClear		29
// # define SelectionRequest	30
// # define SelectionNotify		31
// # define ColormapNotify		32
// # define ClientMessage		33
// # define MappingNotify		34
// # define LASTEvent		35	/* must be bigger than any event # */

#endif