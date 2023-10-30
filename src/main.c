/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:01:33 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/30 16:23:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2 && printf("Usage: ./cub3d PATH_TO_MAP\n"))
		return (-1);
	if (sizeof(argv[1]) < 6
		|| ft_strncmp(".cub", argv[1] + sizeof(argv[1]) - 5, 5))
		return (-2);
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
	game_loop(&game);
	return (0);
}
