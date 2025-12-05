/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/05 17:26:31 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;
	t_vars	mlx_vars;
	t_data	img;

	init_mlx(&mlx_vars, &img);
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
	draw_map(&img, map);
	mlx_loop(mlx_vars.mlx);
	free_map(&map);
}



