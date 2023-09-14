/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:59:54 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/21 20:12:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LONG_INT 9223372036854775807LL

long long int	ft_atol_safe(char *str, long int *result_ptr)
{
	long long int	output;
	int				sign;
	int				overflow_flag;

	overflow_flag = 0;
	sign = 1;
	output = 0;
	while (ft_iswhitespace(str[0]))
		str++;
	while (str[0] == '-' || str[0] == '+')
		if (str[0]++ == '-')
			sign *= -1;
	while (ft_isdigit(str[0]))
	{
		if ((output * 10) + str[0] - '0' > MAX_LONG_INT && overflow_flag++)
			break ;
		else
			output = (output * 10) + str[0]++ - '0';
	}
	output *= sign;
	if (overflow_flag)
		return (-1);
	if (result_ptr != NULL)
		*result_ptr = output;
	return (0);
}
