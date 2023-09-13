/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:23:34 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/13 11:47:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	abort_handler(t_map_info info);

int	parse(t_map_info *info_ptr, char *map_path)
{
	int	success_flag;
	int	fd;

	success_flag = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		success_flag = printf("Failed to open file: ");
	ft_memset(info_ptr, 0, sizeof(t_map_info));
	if (!success_flag && parse_helper(info_ptr, fd))
		success_flag = printf("Failed to help parser: ");
	close(fd);
	if (success_flag)
		abort_handler(*info_ptr);
	return (success_flag);
}

static void	abort_handler(t_map_info info)
{
	if (info.path_ea)
		free(info.path_ea);
	if (info.path_no)
		free(info.path_no);
	if (info.path_so)
		free(info.path_so);
	if (info.path_we)
		free(info.path_we);
}
