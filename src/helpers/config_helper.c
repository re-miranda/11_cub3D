/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:32:29 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/19 10:48:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	game_m_speed(t_game *game)
{
	return (game->move_speed);
}

double	game_r_speed(t_game *game)
{
	return (game->rot_speed);
}

int	game_f_color(t_game *game)
{
	return (game->info.color_f);
}

int	game_c_color(t_game *game)
{
	return (game->info.color_c);
}

char	game_start_orient(t_game *game)
{
	return (game->info.orient);
}
