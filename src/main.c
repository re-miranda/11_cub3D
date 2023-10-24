/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:01:33 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/24 16:34:14 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2 && printf("Usage: ./cub3d PATH_TO_MAP\n"))
		return (-1);
	if (parse(&game.info, argv[1]))
		return (-2);
	if (!game_setup(&game))
	{
		game_destroy(&game);
		return (1);
	}
	if (!game_textures_load(&game))
	{
		game_textures_destroy(&game);
		game_destroy(&game);
		return (-1);
	}
	mlx_hook(game.window, 2, 1L << 0, key_press_listener, &game);
	mlx_hook(game.window, 4, 1 << 2, mouse_listener, &game);
	render_the_screen(&game);
	mlx_loop(game.mlx);
	game_textures_destroy(&game);
	game_destroy(&game);
	return (0);
}
