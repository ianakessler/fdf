/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:06:02 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/11/26 19:27:14 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fill_line(t_map **map, char *line, int row)
{
	int		current_value;
	char	**splited;
	int 	i;

	i = 0;
	splited = ft_split(line, ' ');
	while (i < (*map)->width)
	{
		current_value = ft_atoi(splited[i]);
		(*map)->map[row][i] = current_value;
		i++;
	}
	free_splited(splited);
}

void	populate_matrix(t_map **map, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (i < (*map)->heigth)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		fill_line(map, line, i);
		free(line);
		i++;
	}
	close(fd);
}
