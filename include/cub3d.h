/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:59:06 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/20 15:33:09 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft_gnl_printf.h"
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "define.h"
# include "helpers.h"
# include "engine.h"

int	parse(t_map_info *info_ptr, char *map_path);

#endif
