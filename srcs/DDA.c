/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:20:32 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/03 19:45:33 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_data *data, t_2D_dot *p1, t_2D_dot *p2, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_map(t_data *data, t_map *map, int i, int j)
{
	while (i < map->heigth -1)
	{
		j = 0;
		draw_line(data, map->bd_dots[i][j], map->bd_dots[i + 1][j], map->bd_dots[i][j]->color);
		while (j < map->width -1)
		{
			draw_line(data, map->bd_dots[i][j] , map->bd_dots[i][j+1], map->bd_dots[i][j]->color);
			j++;
			draw_line(data, map->bd_dots[i][j], map->bd_dots[i + 1][j], map->bd_dots[i][j]->color);
		}
		i++;
	}
}

void	draw_line(t_data *data, t_2D_dot *p1, t_2D_dot *p2, int color)
{
	int		i;
	int		step;
	float	x;
	float	y;

	if (abs(p2->x - p1->x) >= abs(p2->y - p1->y))
		step = abs(p2->x - p1->x);
	else
		step = abs(p2->y - p1->y);
	x = p1->x;
	y = p1->y;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put(data, round(x) + WINDOW_WIDTH/2, round(y) + WINDOW_HEIGHT/2, color);
		x += (p2->x - p1->x) / (float)step;
		y += (p2->y - p1->y) / (float)step;
		i++;
	}
}
