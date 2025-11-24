/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/24 18:57:59 by iaratang         ###   ########.fr       */
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
	t_map *mapa;

	mapa = malloc(sizeof(t_map));
	if (argc != 2)
		return 0;

	parse_map(argc, argv[1]);
	int k = count_map_rows(argv[1], &mapa);
	int i = chars_line_counter(argv[1], &mapa);
	init_map(&mapa, k, argv[1]);
	free(mapa);
	return (i);

}

	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	// img.img = mlx_new_image(mlx, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);

	// int i = 0;
	// while (i++ < 100)
	// {

	// 	my_mlx_pixel_put(&img, i, 0, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, 0, i, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, i, 100, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, 100, i, 0x00FF0000);
	// }

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
