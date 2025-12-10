/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:17:15 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/10 18:15:10 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../lib/libft.h"
# include "../includes/get_next_line.h"

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_dot
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_dot;

typedef struct s_2D_dot
{
	int			x;
	int			y;
	int			color;
}				t_2D_dot;

typedef struct s_map
{
	int			width;
	int			heigth;
	t_dot		***dots;
	t_2D_dot	***bd_dots;
}				t_map;

typedef struct s_env
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	t_map		*map;
}				t_env;

//arguments validation
void	file_validator(char *file_name);

//map dimensions
void	malloc_map(t_map **map, char *file_name);
void	populate_matrix(t_map **map, char *file_name);
void	convert_dots(t_map **map);
void	malloc_2d_map(t_map **map);
void	init_mlx(t_env *env);

//frees
void	free_map(t_map **map);
void	free_splited(char **splited);

void	draw_map(t_env *env, t_map *map);

int		close_window(t_env *env);
int		key_handler(int keycode, t_env *env);

//utils
int		count_rows(char *line);
int		ft_atoi_hex(char *str);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	exit_error(char *str);
char	**trim_and_split(char *line);

#endif
