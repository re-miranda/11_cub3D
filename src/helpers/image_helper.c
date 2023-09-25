/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:43:24 by gasouza           #+#    #+#             */
/*   Updated: 2023/09/20 17:11:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*img_pixel_get_at(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = NULL;
	if (img)
		pixel = img->data + ((img->ls * x) + (y * (img->bpp / 8)));
	return (pixel);
}

int	img_color_get_at(t_img *img, int x, int y)
{
	int	index;
	int	color;

	color = 0;
	if (img)
	{
		index = x * img->ls + y * img->bpp / 8;
		color = (*(int *)(img->data + index));
	}
	return (color);
}
