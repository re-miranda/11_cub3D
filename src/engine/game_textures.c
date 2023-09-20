/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:14:26 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 16:03:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*orient_img_path(t_game *game, int orient);

int	game_textures_load(t_game *game)
{
	t_img	*img;
	char	*path;
	int		orient;

	orient = 4;
	while (--orient)
	{
		img = &game->texture[orient];
		path = orient_img_path(game, orient);
		img->mlx = mlx_xpm_file_to_image(game->mlx, path, &img->w, &img->h);
		if (img->mlx == NULL)
		{
			printf("Error when loading texture: %s\n", path);
			return (0);
		}
		img->data = mlx_get_data_addr(img->mlx, &img->bpp, &img->ls, &img->end);
	}
	return (1);
}

static char	*orient_img_path(t_game *game, int orient)
{
	if (orient == NO)
		return (game->info.path_no);
	if (orient == SO)
		return (game->info.path_so);
	if (orient == WE)
		return (game->info.path_we);
	if (orient == EA)
		return (game->info.path_ea);
	return (NULL);
}

void	game_textures_destroy(t_game *game)
{
	int		orient;
	t_img	*img;

	orient = 4;
	while (--orient)
	{
		img = &game->texture[orient];
		if (img->mlx == NULL)
			continue ;
		mlx_destroy_image(game->mlx, img->mlx);
	}
}
