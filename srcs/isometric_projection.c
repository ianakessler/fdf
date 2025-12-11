/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:26:09 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/11 17:24:26 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//2d.x = (3d.x - 3d.y) * cos(30)
//2d.y = (3d.x + 2 * 3d.y + 3d.z) * sin(30)

#include "../includes/fdf.h"

static double	isometric_calc_y(int x, int y, int z, t_map *map);
static double	isometric_calc_x(int x, int y, t_map *map);

void	convert_dots(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->heigth)
	{
		j = 0;
		while (j < (*map)->width)
		{
			(*map)->bd_dots[i][j]->x = isometric_calc_x((*map)->dots[i][j]->x,
					(*map)->dots[i][j]->y, *map);
			(*map)->bd_dots[i][j]->y = isometric_calc_y((*map)->dots[i][j]->x,
					(*map)->dots[i][j]->y, (*map)->dots[i][j]->z, *map);
			(*map)->bd_dots[i][j]->color = (*map)->dots[i][j]->color;
			j++;
		}
		i++;
	}
	free_3D_map(map);
}

static double	isometric_calc_x(int x, int y, t_map *map)
{
	return ((-(x - y) * cos(0.523599) * -map->scale) + WINDOW_WIDTH / 2);
}

static double	isometric_calc_y(int x, int y, int z, t_map *map)
{
	return (((-(x + 2 * y - (0.5 * z)) * sin(0.523599)) * map->scale) + WINDOW_HEIGHT / 6);
}

void	malloc_2d_map(t_map **map)
{
	int	i;
	int	j;

	if (!map || !*map || !(*map))
		return ;
	(*map)->bd_dots = malloc(sizeof(*(*map)->bd_dots) * (*map)->heigth);
	if (!(*map)->bd_dots)
		return ;
	i = 0;
	while (i < (*map)->heigth)
	{
		(*map)->bd_dots[i] = malloc(sizeof(*(*map)->bd_dots[i])
				* (*map)->width);
		j = 0;
		while (j < (*map)->width)
		{
			(*map)->bd_dots[i][j] = malloc(sizeof(t_2D_dot));
			j++;
		}
		i++;
	}
}

void	set_map_scale(t_map **map)
{
	int	h;
	int	w;
	int	total_size;

	h = (*map)->heigth;
	w = (*map)->width;
	total_size = h * w;
	if (total_size > 100000)
		(*map)->scale = -1;
	else if (total_size <= 100000 && total_size > 10000)
		(*map)->scale = -3;
	else if (total_size <= 10000 && total_size > 5000)
		(*map)->scale = -5;
	else if (total_size <= 5000 && total_size > 1000)
		(*map)->scale = -10;
	else if (total_size < 1000)
		(*map)->scale = -15;

}
