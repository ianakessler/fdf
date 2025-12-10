/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:57 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/10 18:01:44 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_env	env;

	init_mlx(&env);
	map = malloc(sizeof(t_map));
	if (argc != 2)
		exit_error("Wrong number of arguments. Exiting...\n");
	file_validator(argv[1]);
	malloc_map(&map, argv[1]);
	populate_matrix(&map, argv[1]);
	convert_dots(&map);
	draw_map(&env, map);
	mlx_put_image_to_window(env.mlx, env.mlx_win, env.img, 0, 0);
	env.map = map;
	mlx_key_hook(env.mlx_win, &key_handler, &env);
	mlx_hook(env.mlx_win, 17, 0, close_window, &env);
	mlx_loop(env.mlx);
	free_map(&map);
}
