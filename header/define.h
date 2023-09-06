/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEFINE.H                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:26:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/09/06 16:00:29 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define WALL 1
# define FLOOR 1
# define EMPTY 1
# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_vect {
	double	x;
	double	y;
}	t_vect;

typedef struct s_map_info {
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		color_f;
	int		color_c;
	char	**map;
	int		m_height;
	int		m_width;
	char	dir;
	t_vect	pos;
}	t_map_info;