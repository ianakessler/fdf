/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/26 19:41:22 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}


int	main(int argc, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments, exiting...\n", 1);
		exit(1);
	}
	file_validator(argv[1]);
	malloc_map(&map, argv[1]);
	populate_matrix(&map, argv[1]);
	check_colors(argv[1], map);

	// int i = 0;
	// int j;

	// while (i < map->heigth)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 	{
	// 		printf("%i ", map->colors[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }


	free_map(&map);
}



