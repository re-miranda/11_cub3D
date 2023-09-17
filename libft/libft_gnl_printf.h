/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl_printf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:17:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/15 10:49:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_PRINTF_H
# define LIBFT_GNL_PRINTF_H

# include "./libft/libft.h"
int		ft_printf(const char *format_string, ...);
char	*ft_get_whole_file(int fd);
char	*ft_get_next_line(int fd);

#endif
