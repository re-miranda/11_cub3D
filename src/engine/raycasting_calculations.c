/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:06:09 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 21:42:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_direction(t_game *game, t_raycast *rc, int screen_col);
void	calculate_delta_distance(t_raycast *rc);
void	calculate_step_and_side_dist(t_game *game, t_raycast *rc);
void	calculate_perpendicular_wall_distance(t_raycast *rc);
void	calculate_where_wall_was_hit(t_game *game, t_raycast *rc);

void	calculate_ray_direction(t_game *game, t_raycast *rc, int screen_col)
{
	double	screen_col_to_cast;

	screen_col_to_cast = 2 * screen_col / (double) WINDOW_W - 1;
	rc->ray_dir.x = dir_get_x(game) + fov_get_x(game) * screen_col_to_cast;
	rc->ray_dir.y = dir_get_y(game) + fov_get_y(game) * screen_col_to_cast;
}

void	calculate_delta_distance(t_raycast *rc)
{
	double	big_number;

	big_number = 1e30;
	if (rc->ray_dir.x == 0)
		rc->delta_dist.x = big_number;
	else
		rc->delta_dist.x = fabs(1 / rc->ray_dir.x);
	if (rc->ray_dir.y == 0)
		rc->delta_dist.y = big_number;
	else
		rc->delta_dist.y = fabs(1 / rc->ray_dir.y);
}

void	calculate_step_and_side_dist(t_game *game, t_raycast *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (pos_get_x(game) - r->pos.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->pos.x + 1.0 - pos_get_x(game)) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (pos_get_y(game) - r->pos.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->pos.y + 1.0 - pos_get_y(game)) * r->delta_dist.y;
	}
}

void	calculate_perpendicular_wall_distance(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist.x - rc->delta_dist.x);
	else
		rc->perp_wall_dist = (rc->side_dist.y - rc->delta_dist.y);
}

void	calculate_where_wall_was_hit(t_game *game, t_raycast *rc)
{
	if (rc->side == 0)
		rc->wall_x_hit = pos_get_y(game) + rc->perp_wall_dist * rc->ray_dir.y;
	else
		rc->wall_x_hit = pos_get_x(game) + rc->perp_wall_dist * rc->ray_dir.x;
	rc->wall_x_hit -= floor((rc->wall_x_hit));
}
