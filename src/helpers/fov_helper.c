/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:33:35 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 17:12:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	fov_get_x(t_game *game)
{
	return (game->fov.x);
}

double	fov_get_y(t_game *game)
{
	return (game->fov.y);
}

void	fov_set_x(t_game *game, double x)
{
	game->fov.x = x;
}

void	fov_set_y(t_game *game, double y)
{
	game->fov.y = y;
}
