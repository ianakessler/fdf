/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:33:47 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/12/11 14:17:36 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map **map)
{
	int	i;
	int	j;

	if (!map || !(*map))
		return ;
	i = 0;
	while (i < (*map)->heigth)
	{
		j = 0;
		while (j < (*map)->width)
		{
			free((*map)->bd_dots[i][j]);
			j++;
		}
		free((*map)->bd_dots[i]);
		i++;
	}
	free((*map)->bd_dots);
	free(*map);
}

void	free_3D_map(t_map **map)
{
	int	i;
	int	j;

	if (!map || !(*map))
		return ;
	i = 0;
	while (i < (*map)->heigth)
	{
		j = 0;
		while (j < (*map)->width)
		{
			free((*map)->dots[i][j]);
			j++;
		}
		free((*map)->dots[i]);
		i++;
	}
	free((*map)->dots);
}

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	splited = NULL;
}
