/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:37:37 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/22 03:24:12 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_function(t_game *game)
{
	if (game->runtime_action & MOVE_UP)
		player_move_up(game);
	if (game->runtime_action & MOVE_DOWN)
		player_move_down(game);
	if (game->runtime_action & MOVE_LEFT)
		player_move_left(game);
	if (game->runtime_action & MOVE_RIGHT)
		player_move_right(game);
	if (game->runtime_action & LOOK_RIGHT)
		fov_rotate_right(game);
	if (game->runtime_action & LOOK_LEFT)
		fov_rotate_left(game);
	render_the_screen(game);
	return (0);
}
