/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_derection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:31:43 by gasouza           #+#    #+#             */
/*   Updated: 2023/10/22 15:31:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_info(t_game *game, int x, int y, char *info);
static void	calculate_center(t_ivect *center, t_game *game);

void	display_direction(t_game *game)
{
	t_ivect	dir;
	t_ivect	center;
	char	*pixel;
	int		x;
	int		y;

	calculate_center(&center, game);
	dir.x = center.x + (game->dir.x * 8);
	dir.y = center.y + (game->dir.y * 8);
	x = dir.x - 2;
	while (x < dir.x + 2)
	{
		y = dir.y - 2;
		while (y < dir.y + 2)
		{
			pixel = img_pixel_get_at(&game->screen, x, y);
			*(int *)pixel = MMAP_PCOLOR;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen.mlx, 0, 0);
	print_info(game, center.y - 3, center.x - 16, "N");
	print_info(game, center.y - 2, center.x + 24, "S");
	print_info(game, center.y - 22, center.x + 4, "W");
	print_info(game, center.y + 15, center.x + 4, "E");
}

static void	calculate_center(t_ivect *center, t_game *game)
{
	char	*pixel;
	int		x;
	int		y;

	center->x = 10 + (60 / 2);
	center->y = WINDOW_W - (10 + 60) / 2;
	x = center->x - 1;
	while (x < center->x + 1)
	{
		y = center->y - 1;
		while (y < center->y + 1)
		{
			pixel = img_pixel_get_at(&game->screen, x, y);
			*(int *)pixel = MMAP_WCOLOR;
			y++;
		}
		x++;
	}
}

static void	print_info(t_game *game, int x, int y, char *info)
{
	mlx_string_put(game->mlx, game->window, x, y, MMAP_WCOLOR, info);
}
