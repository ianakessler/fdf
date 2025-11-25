/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang@student.42sp.org.br <iaratang>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:17:15 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/25 21:25:28 by iaratang@st      ###   ########.fr       */
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

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_map
{
	int			width;
	int			heigth;
	int			**map;
	int			colors;
}				t_map;

//arguments validation
void	file_validator(char *file_name);

//testes 
void    malloc_map(t_map **map, char *file_name);
void    populate_matrix(t_map **map, char *file_name);

//frees
void free_map(t_map **map);
void free_splited(char **splited);

//utils
int count_rows(char *line);

#endif
