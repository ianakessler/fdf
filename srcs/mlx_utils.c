/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:39:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/05 18:16:08 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_mlx(t_vars *mlx_vars, t_data *img)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->mlx_win = mlx_new_window(mlx_vars->mlx, 1920, 1080, "");
	img->img = mlx_new_image(mlx_vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_len,
								&img->endian);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->mlx_win, img->img, 0, 0);
	mlx_key_hook(mlx_vars->mlx_win, &key_hanler, &mlx_vars);
}

int	key_hanler(int keycode, t_data *data, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_window(data, vars);
	}
	return (0);
}

int	close_window(t_data *data, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, data->img);
	mlx_destroy_window(data->img, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	if (vars->mlx != NULL)
		free(vars->mlx);
	return (0);
}
