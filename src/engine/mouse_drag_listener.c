/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_drag_listener.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:50 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/18 20:57:12 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_drag_listener(int x, int y, t_game *game)
{
	(void)x;
	if (y % 5 != 0)
		return (0);
	if (game->mouse_rot > y)
		fov_rotate_right(game);
	else
		fov_rotate_left(game);
	game->mouse_rot = y;
	render_the_screen(game);
	return (0);
}
