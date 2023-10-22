/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:01:18 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 03:22:59 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_fov_rotate_left(t_game *game)
{
	game->runtime_action = game->runtime_action | LOOK_LEFT;
}

void	set_fov_rotate_right(t_game *game)
{
	game->runtime_action = game->runtime_action | LOOK_RIGHT;
}
