/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:50:13 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/24 22:03:47 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	expose_hook(t_game *game);
static int	close_game_button(t_game *game);

void	game_loop(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press_listener, game);
	mlx_hook(game->window, 4, 1 << 2, mouse_listener, game);
	mlx_expose_hook(game->window, expose_hook, game);
	mlx_hook(game->window, 17, 0, close_game_button, game);
	mlx_loop(game->mlx);
	game_textures_destroy(game);
	game_destroy(game);
}

static int	expose_hook(t_game *game)
{
	render_the_screen(game);
	return (0);
}

static int	close_game_button(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (1);
}
