/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/02 16:24:37 by iaratang         ###   ########.fr       */
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
	convert_dots(&map);

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
								&img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	int i = 0;
	int j;

	while (i < map->heigth)
	{
		j = 0;
		while (j < map->width)
		{
			my_mlx_pixel_put(&img, (map->bd_dots[i][j]->x) + WINDOW_WIDTH/2, (map->bd_dots[i][j]->y) + WINDOW_HEIGHT/2 , map->bd_dots[i][j]->color);

			printf("x: %i, y: %i", map->bd_dots[i][j]->x + WINDOW_WIDTH/2, map->bd_dots[i][j]->y + WINDOW_HEIGHT/2);
			j++;
		}
		printf("\n-------------\n");
		i++;
	}


	mlx_loop(mlx);
	free_map(&map);
}



