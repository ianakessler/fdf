/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:26:09 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/10 17:56:24 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//2d.x = (3d.x - 3d.y) * cos(30)
//2d.y = (3d.x + 2 * 3d.y + 3d.z) * sin(30)

#include "../includes/fdf.h"

static double	isometric_calc_y(int x, int y, int z);
static double	isometric_calc_x(int x, int y);

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
					(*map)->dots[i][j]->y);
			(*map)->bd_dots[i][j]->y = isometric_calc_y((*map)->dots[i][j]->x,
					(*map)->dots[i][j]->y, (*map)->dots[i][j]->z);
			(*map)->bd_dots[i][j]->color = (*map)->dots[i][j]->color;
			j++;
		}
		i++;
	}
}

static double	isometric_calc_x(int x, int y)
{
	return (((x - y) * cos(0.523599) * 6) + WINDOW_WIDTH / 2);
}

static double	isometric_calc_y(int x, int y, int z)
{
	return ((((x + 2 * y + z) * sin(0.523599)) * -6) + WINDOW_HEIGHT / 2);
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
