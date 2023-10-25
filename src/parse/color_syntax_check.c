/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color_syntax_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:36:51 by rmiranda          #+#    #+#             */
/*   Updated: 2023/10/24 16:37:12 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_syntax_check(char *line)
{
	static int	recursive_count;
	int			three_digit_limit;

	three_digit_limit = 3;
	while (line[0] == ' ')
		line++;
	if (!ft_isdigit(line[0]))
		return (0);
	while (ft_isdigit(line[0]) && three_digit_limit--)
		line++;
	if (recursive_count++ < 2)
	{
		if (line[0] != ',')
			return (0);
		line++;
		return (color_syntax_check(line));
	}
	recursive_count = 0;
	if (line[0])
		return (0);
	return (1);
}
