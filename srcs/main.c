/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/19 16:40:02 by iaratang         ###   ########.fr       */
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
	if (argc != 2)
		return 0;
	int fd = open(argv[1], O_RDONLY);
	parse_map(argc, fd, argv[1]);
	int i = chars_line_counter(fd);
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
