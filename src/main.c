/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:58:57 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/20 16:06:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// static void	destroy(t_map_info info);

// static void	print_map(t_map_info info)
// {
// 	int	index;
// 	int	mask;

// 	printf("%s\n", info.path_no);
// 	printf("%s\n", info.path_so);
// 	printf("%s\n", info.path_we);
// 	printf("%s\n", info.path_ea);
// 	mask = 0x000000ff;
// 	printf("F %i, %i, %i, %i\n", info.color_f>>24, mask & info.color_f>>16, mask & info.color_f>>8, mask & info.color_f);
// 	printf("C %i, %i, %i, %i\n", info.color_c>>24, mask & info.color_c>>16, mask & info.color_c>>8, mask & info.color_c);
// 	if (info.map)
// 	{
// 		index = 0;
// 		while (index < info.m_height)
// 			printf("%s", info.map[index++]);
// 	}
// 	printf("\n");
// }

// int	main_disabled(int argc, char *argv[])
// {
// 	t_map_info	info;

// 	printf("# CUB3D By gasouza & rmiranda (develop version)\n\n");
// 	if (argc != 2 && printf("Usage: ./cub3d PATH_TO_MAP\n"))
// 		return (-1);
// 	if (parse(&info, argv[1]) && printf("Error: Could not parse the map.\n"))
// 		return (-2);
// 	printf("# Map Loaded Successfully:\n");
// 	print_map(info);
// 	destroy(info);
// 	return (0);
// }

// static void	destroy(t_map_info info)
// {
// 	printf("# Clean exit\n");
// 	if (info.path_ea)
// 		free(info.path_ea);
// 	if (info.path_no)
// 		free(info.path_no);
// 	if (info.path_so)
// 		free(info.path_so);
// 	if (info.path_we)
// 		free(info.path_we);
// 	if (info.map)
// 	{
// 		while (info.m_height--)
// 			free(info.map[info.m_height]);
// 		free(info.map);
// 	}
// 	(void)info;
// }
