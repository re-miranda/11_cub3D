/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:58:57 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/13 11:23:48 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy(t_map_info info);

int	main(int argc, char *argv[])
{
	t_map_info	info;

	printf("CUB3D By gasouza & rmiranda (develop version)\n\n");
	if (argc != 2 && printf("Usage: ./cub3d PATH_TO_MAP\n"))
		return (-1);
	if (parse(&info, argv[1]) && printf("Error: Could not parse the map.\n"))
		return (-2);
	printf("Map Loaded Successfully\n");
	destroy(info);
	printf("Clean exit\n");
	return (0);
}

static void	destroy(t_map_info info)
{
	(void)info;
}
