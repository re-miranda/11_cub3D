/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:35:32 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/22 15:51:06 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_the_screen(t_game *game);

void	render_the_screen(t_game *game)
{
	clean_the_screen(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->window, game->screen.mlx, 0, 0);
}

static void	clean_the_screen(t_game *game)
{
	int		x;
	int		y;
	char	*pixel;

	x = 0;
	while (x < WINDOW_H)
	{
		y = 0;
		while (y < WINDOW_W)
		{
			pixel = img_pixel_get_at(&game->screen, x, y);
			*(int *)pixel = 0x0;
			y++;
		}
		x++;
	}
}
