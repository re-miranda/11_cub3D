/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:58:11 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/26 16:28:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_minimap(t_game *game, t_ivect *start, t_ivect *end);
static char	*minimap_pixel(t_img *screen, int x, int y);
static int	is_empty_coord(t_game *game, t_ivect *c, t_ivect *s, t_ivect *e);

void	display_minimap(t_game *game)
{
	t_ivect	start;
	t_ivect	end;

	start.x = 0;
	end.x = MMAP_W / game->mmap_zoom;
	if (game->pos.y + 1 >= end.x)
	{
		end.x = game->pos.y + 2;
		start.x = end.x - MMAP_W / game->mmap_zoom;
	}
	if (end.x > map_height(game))
		end.x = map_height(game);
	start.y = 0;
	end.y = MMAP_H / game->mmap_zoom;
	if (game->pos.x + 1 >= end.y)
	{
		end.y = game->pos.x + 2;
		start.y = end.y - map_height(game) / game->mmap_zoom;
	}
	if (start.y < 0)
		start.y = 0;
	if (end.y > map_width(game))
		end.y = map_width(game);
	render_minimap(game, &start, &end);
}

static void render_minimap(t_game *g, t_ivect *start, t_ivect *end)
{
	t_ivect	coord;
	t_ivect	loop;
	char	*pixel;

	loop.x = -1;
	while (++loop.x < MMAP_H)
	{
		loop.y = -1;
		while (++loop.y < MMAP_W)
		{
			pixel = minimap_pixel(&g->screen, loop.x, loop.y);
			coord.x = start->x + (loop.y / g->mmap_zoom);
			coord.y = start->y + (loop.x / g->mmap_zoom);
			if (is_empty_coord(g, &coord, start, end))
				continue ;
			else if (coord.y == (int) g->pos.x && coord.x == (int) g->pos.y)
				*(int *)pixel = MMAP_PCOLOR;
			else if (map_at(g, coord.y, coord.x) == WALL)
				*(int *)pixel = MMAP_WCOLOR;
			else if (map_at(g, coord.y, coord.x) == FLOOR)
				*(int *)pixel = MMAP_FCOLOR;
		}
	}
}

static char	*minimap_pixel(t_img *screen, int x, int y)
{
	return (img_pixel_get_at(screen, x + 10, y + 10));
}

static int	is_empty_coord(t_game *game, t_ivect *c, t_ivect *s, t_ivect *e)
{
	(void)s;
	if (c->x >= e->x || c->y >= e->y)
		return (1);
	if (map_at(game, c->y, c->x) == EMPTY)
		return (1);
	return (0);
}
