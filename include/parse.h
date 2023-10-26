/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/24 14:55:31 by rmiranda         ###   ########.fr       */
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
# define ALLOWED_CHARACTERS " 01NWSE"

// Getter
int		add_next_instruction(char *line, t_map_info *info_ptr);
int		parse(t_map_info *info_ptr, char *map_path);

// Validation
int		map_validation(t_map_info *info_ptr);
int		add_line_to_map(t_map_info *info_ptr, char *line);
char	**normalize_map(t_map_info *info_ptr);
int		assert_is_not_surrounded_by_wall(t_map_info info);
void	space_injest_func(unsigned int nb, char *c);
void	parse_destroy(t_map_info info);
int		color_syntax_check(char *line);

#endif