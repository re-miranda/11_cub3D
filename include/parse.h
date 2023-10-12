/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/12 13:38:31 by gasouza          ###   ########.fr       */
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
int		add_next_instruction(char *line, t_map_info *info_ptr);
int		add_line_to_map(t_map_info *info_ptr, char *line);

// Validation
int		map_validation(t_map_info *info_ptr);
char	**normalize_map(t_map_info *info_ptr);

#endif