/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:07:44 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/21 18:37:23 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_safe(char *str, int *result_ptr)
{
	int			sign;
	long int	output;

	sign = 1;
	output = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output *= 10;
		output += (int)(*str) - 48;
		str++;
	}
	output *= sign;
	if (output > 2147483647 || output < -2147483648)
		return (1);
	if (result_ptr)
		*result_ptr = (int)output;
	return (0);
}
