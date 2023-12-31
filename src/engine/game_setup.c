/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:32 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 18:09:23 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_screen_image_buffer_create(t_game *game);
static void	game_set_default_values(t_game *game);
static int	game_mlx_setup(t_game *game);
static void	game_set_orientation(t_game *game);

int	game_setup(t_game *game)
{
	game_set_default_values(game);
	if (!game_mlx_setup(game))
		return (0);
	game_set_orientation(game);
	game_screen_image_buffer_create(game);
	return (1);
}

static void	game_set_default_values(t_game *game)
{
	int	orient;

	orient = 4;
	while (orient--)
	{
		game->texture[orient].mlx = NULL;
		game->texture[orient].data = NULL;
	}
	game->mlx = NULL;
	game->window = NULL;
	game->screen.mlx = NULL;
	game->screen.data = NULL;
	game->pos = game->info.pos;
	game->dir.x = -1;
	game->dir.y = 0;
	game->fov.x = 0;
	game->fov.y = 0.60;
	game->mouse_rot = 0;
	game->mmap = 0;
	game->mmap_zoom = MMAP_MIN_ZOOM;
	game->rot_speed = ROT_SPEED;
	game->move_speed = MOV_SPEED;
}

static void	game_set_orientation(t_game *game)
{
	if (game->info.orient == 'E')
	{
		dir_set_x(game, 0);
		dir_set_y(game, 1);
		fov_set_x(game, 0.6);
		fov_set_y(game, 0);
	}
	if (game->info.orient == 'S')
	{
		dir_set_x(game, 1);
		dir_set_y(game, 0);
		fov_set_x(game, 0);
		fov_set_y(game, -0.6);
	}
	if (game->info.orient == 'W')
	{
		dir_set_x(game, 0);
		dir_set_y(game, -1);
		fov_set_x(game, -0.6);
		fov_set_y(game, 0);
	}
}

static void	game_screen_image_buffer_create(t_game *game)
{
	int		*bpp;
	int		*ls;
	int		*endian;
	t_img	*screen;

	screen = &game->screen;
	screen->path = NULL;
	bpp = &screen->bpp;
	ls = &screen->ls;
	endian = &screen->end;
	screen->mlx = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	screen->data = mlx_get_data_addr(screen->mlx, bpp, ls, endian);
}

static int	game_mlx_setup(t_game *game)
{
	game->window = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		printf("Error when initializing MLX\n");
		return (0);
	}
	game->window = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, WINDOW_T);
	if (game->window == NULL)
	{
		printf("Error when initializing WINDOW\n");
		free(game->mlx);
		game->mlx = NULL;
		return (0);
	}
	return (1);
}
