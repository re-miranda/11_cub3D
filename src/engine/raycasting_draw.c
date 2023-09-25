/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:14:12 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 21:22:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall_draw_start_and_end(t_raycast *rc);
static int	texture_x(t_raycast *rc);
static int	texture_color_at(t_game *game, t_raycast *rc, int x, int y);
static void	draw_to_screen(t_game *game, t_raycast *rc, int screen_column);

void	draw_screen_column(t_game *game, t_raycast *rc, int screen_column)
{
	rc->wall_line_h = (int)(WINDOW_H / rc->perp_wall_dist);
	rc->rate = 1.0 * TEXTURE_H / rc->wall_line_h;
	calculate_wall_draw_start_and_end(rc);
	draw_to_screen(game, rc, screen_column);
}

static void	calculate_wall_draw_start_and_end(t_raycast *rc)
{
	rc->wall_draw_start = -rc->wall_line_h / 2 + WINDOW_H / 2;
	if (rc->wall_draw_start < 0)
		rc->wall_draw_start = 0;
	rc->wall_draw_end = rc->wall_line_h / 2 + WINDOW_H / 2;
	if (rc->wall_draw_end >= WINDOW_H)
		rc->wall_draw_end = WINDOW_H - 1;
}

static void	draw_to_screen(t_game *game, t_raycast *rc, int screen_column)
{
	double	texture_height;
	int		texture_y;
	char	*pixel;
	int		color;
	int		x;

	texture_height = rc->wall_draw_start - WINDOW_H / 2 + rc->wall_line_h / 2;
	texture_height *= rc->rate;
	x = 0;
	while (x < WINDOW_H)
	{
		pixel = img_pixel_get_at(&game->screen, x, screen_column);
		if (x >= rc->wall_draw_start && x <= rc->wall_draw_end)
		{
			texture_y = ((int)texture_height & (TEXTURE_H - 1));
			color = texture_color_at(game, rc, texture_x(rc), texture_y);
			*(int *)pixel = color;
			texture_height += rc->rate;
		}
		else if (x < WINDOW_H / 2)
			*(int *)pixel = game_c_color(game);
		else
			*(int *)pixel = game_f_color(game);
		x++;
	}
}

static int	texture_x(t_raycast *rc)
{
	int	texture_column;

	texture_column = (int)(rc->wall_x_hit * (double) TEXTURE_W);
	if (rc->side == 0 && rc->ray_dir.x > 0)
		texture_column = TEXTURE_W - texture_column - 1;
	if (rc->side == 1 && rc->ray_dir.y < 0)
		texture_column = TEXTURE_W - texture_column - 1;
	return (texture_column);
}

static int	texture_color_at(t_game *game, t_raycast *rc, int x, int y)
{
	t_img	*texture;

	texture = &game->texture[rc->orient];
	return (img_color_get_at(texture, y, x));
}
