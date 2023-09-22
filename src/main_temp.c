/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:01:33 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 09:24:34 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

void temp_config_create(t_game *game)
{
	int map_w = 16;
	int	map_h = 16;

	game->info.path_no = strdup("./img/red.xpm");
	game->info.path_so = strdup("./img/yellow.xpm");
	game->info.path_we = strdup("./img/pink.xpm");
	game->info.path_ea = strdup("./img/blue.xpm");
	
	char map[16][16] = {
		{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,0,0,'N',0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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
	
	game->info.map = malloc(map_h * sizeof(char *));

	for (int x = 0; x < map_h; x++) {
		game->info.map[x] = malloc(map_w);
		for (int y = 0; y < map_w; y++) {

			char element = map[x][y];
			
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

	game->info.m_width = map_w;
	game->info.m_height = map_h;

	printf("Temporary Configuration: created!\n");
}

void temp_config_destroy(t_game *game)
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

void print_temp_map(t_game *game)
{
	printf("\n");
	for (int x = 0; x < game->info.m_height; x++)
	{
		for (int y = 0; y < game->info.m_width; y++)
		{
			char element = game->info.map[x][y];
			if (element == WALL) 		printf("#");
			else if (element == FLOOR) 	printf("_");
			else 						printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int	main()
{
	t_game	game;

	temp_config_create(&game);
	
	if(!game_setup(&game))
	{
		temp_config_destroy(&game);
		return (1);
	}
	printf("Game Setup: created!\n");
		
	if(game_textures_load(&game))
		printf("Textures: loaded!\n");
		
	game_textures_destroy(&game);
	printf("Textures: destroyed!\n");
	
	game_destroy(&game);
	printf("Game Setup: destroyed!\n");
	
	temp_config_destroy(&game);
	
	return (0);
}
