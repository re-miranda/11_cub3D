/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/09 21:32:27 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "define.h"
# include "libftplus.h"
# include <stdio.h>
# include <fcntl.h>

int	parse_getter(t_map_info *info_ptr, int map_fd);
int	map_validation(t_map_info *info_ptr);
int	textures_validation(t_map_info *info_ptr);
char	**normalize_map(t_map_info *info_ptr);

#endif