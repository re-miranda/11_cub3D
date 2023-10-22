/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/22 14:33:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "cub3d.h"
# include <stdio.h>
# include <fcntl.h>

# define SKIP_NL 1
# define KEEP_NEWLINE 0
# define C 1
# define F 0

// Getter
int	add_next_instruction(char *line, t_map_info *info_ptr);
int	add_line_to_map(t_map_info *info_ptr, char *line);

// Validation
int		map_validation(t_map_info *info_ptr);
char	**normalize_map(t_map_info *info_ptr);
int		assert_is_not_surrounded_by_wall(t_map_info info);
int		assert_is_exposed_floor(t_map_info info, int xx, int yy);
int		bounderies_check_horizontal_axis(t_map_info info, int xx, int yy);
int		bounderies_check_vertical_axis(t_map_info info, int xx, int yy);

#endif