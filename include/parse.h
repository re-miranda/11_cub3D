/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/03 15:31:31 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "define.h"
# include "libft_gnl_printf.h"
# include <stdio.h>
# include <fcntl.h>

int	parse_helper(t_map_info *info_ptr, int map_fd);
int	map_validation(t_map_info *info_ptr);

#endif