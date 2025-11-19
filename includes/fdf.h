/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:17:15 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/19 17:35:55 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../lib/libft.h"
#include "../includes/get_next_line.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


//structs

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_3Ddot
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_3Ddot;

//arguments validation
void	parse_map(int argc, int fd, char	*file);


//tests
int	chars_line_counter(int fd);
int	count_numbers_in_line(char *line);

#endif
