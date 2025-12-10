/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:39:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/10 18:02:52 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->mlx_win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	env->mlx_win = mlx_new_window(env->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "display");
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->addr = mlx_get_data_addr(env->img,
			&env->bits_per_pixel, &env->line_len, &env->endian);
}

int	close_window(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	if (env->mlx != NULL)
		free(env->mlx);
	free_map(&env->map);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		close_window(env);
		exit(0);
	}
	return (0);
}
