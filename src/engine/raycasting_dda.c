/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:12:43 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 21:14:24 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_dda(t_game *game, t_raycast *rc)
{
	while (1)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->pos.x += rc->step.x;
			rc->side = 0;
			if (rc->pos.x < pos_get_x(game))
				rc->orient = NO;
			else
				rc->orient = SO;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->pos.y += rc->step.y;
			rc->side = 1;
			if (rc->pos.y < pos_get_y(game))
				rc->orient = WE;
			else
				rc->orient = EA;
		}
		if (map_at(game, rc->pos.x, rc->pos.y) != FLOOR)
			break ;
	}
}
