/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:01:11 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 21:11:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_raycast	rc;
	int			screen_col;

	screen_col = 0;
	while (screen_col < WINDOW_W)
	{
		calculate_ray_direction(game, &rc, screen_col);
		calculate_delta_distance(&rc);
		rc.pos.x = pos_get_x(game);
		rc.pos.y = pos_get_y(game);
		calculate_step_and_side_dist(game, &rc);
		calculate_dda(game, &rc);
		calculate_perpendicular_wall_distance(&rc);
		calculate_where_wall_was_hit(game, &rc);
		draw_screen_column(game, &rc, screen_col);
		screen_col++;
	}
}
