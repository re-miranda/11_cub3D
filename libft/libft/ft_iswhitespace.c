/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:53:52 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/15 02:38:28 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(int character)
{
	if (character == '\t' || character == '\n'
		|| character == '\v' || character == '\f'
		|| character == '\r' || character == ' ')
		return (1);
	return (0);
}
