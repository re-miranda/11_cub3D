/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:01:33 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/03 16:16:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include <string.h>

static void temp_config_create(t_game *game);
static void temp_config_destroy(t_game *game);

static void	print_map(t_map_info info)
{
	int	index;
	int	index2;
	int	mask;

	printf("%s\n", info.path_no);
	printf("%s\n", info.path_so);
	printf("%s\n", info.path_we);
	printf("%s\n", info.path_ea);
	mask = 0x000000ff;
	printf("F %i, %i, %i, %i\n", info.color_f>>24, mask & info.color_f>>16, mask & info.color_f>>8, mask & info.color_f);
	printf("C %i, %i, %i, %i\n", info.color_c>>24, mask & info.color_c>>16, mask & info.color_c>>8, mask & info.color_c);
	if (info.map)
	{
		index = 0;
		while (index < info.m_height)
		{
			index2 = 0;
			while (index2 < info.m_width)
				printf("%i", (int)info.map[index][index2++]);
			printf("\n");
			index++;
		}
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_game	game;

	// Game startup functions
	// ---
	// temp_config_create(&game);
	if (argc != 2 && printf("Usage: ./cub3d PATH_TO_MAP\n"))
		return (-1);
	if (parse(&game.info, argv[1]) && printf("Error: Could not parse the map.\n"))
		return (-2);
	
	if(!game_setup(&game))
	{
		temp_config_destroy(&game);
		return (1);
	}
	printf("Game Setup: created!\n");
	print_map(game.info);
		
	if(game_textures_load(&game))
		printf("Textures: loaded!\n");
	// ---

	// Game main loop and config
	// ---
	render_the_screen(&game);
	mlx_hook(game.window, 2, 1L<<0, key_listener, &game); //keypess
	mlx_put_image_to_window(game.mlx, game.window, game.screen.mlx, 0, 0);
	mlx_loop(game.mlx);
	// ---

	// Game shutdown functions
	// ---
	game_textures_destroy(&game);
	printf("Textures: destroyed!\n");
	
	game_destroy(&game);
	printf("Game Setup: destroyed!\n");
	
	temp_config_destroy(&game);
	// ---

	return (0);
}

static void temp_config_create(t_game *game)
{
	game->info.m_width = 16;
	game->info.m_height = 16;

	game->info.path_no = strdup("./img/red.xpm");
	game->info.path_so = strdup("./img/yellow.xpm");
	game->info.path_we = strdup("./img/pink.xpm");
	game->info.path_ea = strdup("./img/blue.xpm");
	
	char map[16][16] = {
		{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,'N',0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
	game->info.map = malloc(game->info.m_height * sizeof(char *));
	game->info.color_c = 0x00000540;	// Blue
	game->info.color_f = 0x003d1100;	// Brown

	for (int x = 0; x < game->info.m_height; x++) {
		game->info.map[x] = malloc(game->info.m_width);
		for (int y = 0; y < game->info.m_width; y++) {

			char element = map[y][x];
			
			if (element != FLOOR && element != WALL && element != EMPTY) // Player positon
			{
				game->info.pos.y = y;
				game->info.pos.x = x;
				game->info.orient = element;
				element = FLOOR;
			}
			
			game->info.map[x][y] = element;
		}
	}

	game->info.m_width = game->info.m_width;
	game->info.m_height = game->info.m_height;

	printf("Temporary Configuration: created!\n");
}

static void temp_config_destroy(t_game *game)
{
	
	free(game->info.path_no);
	free(game->info.path_so);
	free(game->info.path_we);
	free(game->info.path_ea);

	for (int x = 0; x < 16; x++) {
		free(game->info.map[x]);
	}
	
	free(game->info.map);

		printf("Temporary Configuration: destroyed!\n");
}
