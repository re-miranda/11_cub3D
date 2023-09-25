/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:14:02 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 15:51:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fov_rotation_with_mouse_drag(int button, int y, t_game *game);
static void	minimap_zoom_with_mouse_scroll(int button, t_game *game);

int	mouse_listener(int button, int x, int y, t_game *game)
{
	(void)x;
	fov_rotation_with_mouse_drag(button, y, game);
	minimap_zoom_with_mouse_scroll(button, game);
	render_the_screen(game);
	return (0);
}

static void	fov_rotation_with_mouse_drag(int button, int y, t_game *game)
{
	if (button == 4)
		game->mouse_rot = y;
}

static void	minimap_zoom_with_mouse_scroll(int button, t_game *game)
{
	if (game->mmap)
	{
		if (button == MOUSE_SCROLL_UP && game->mmap_zoom > MMAP_MIN_ZOOM)
			game->mmap_zoom--;
		if (button == MOUSE_SCROLL_DOWN && game->mmap_zoom < MMAP_MAX_ZOOM)
			game->mmap_zoom++;
	}
}
