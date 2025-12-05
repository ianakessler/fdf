/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:06:02 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/12/05 18:35:13 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*get_color(char **splited, int i);

static void	fill_line(t_map **map, char *line, int row)
{
	int		current_value;
	char	**splited;
	char	*color_string;
	int		i;

	i = 0;
	splited = ft_split(line, ' ');
	while (i < (*map)->width)
	{
		current_value = ft_atoi(splited[i]);
		(*map)->dots[row][i]->x = row;
		(*map)->dots[row][i]->y = i;
		(*map)->dots[row][i]->z = current_value;
		color_string = get_color(splited, i);
		if (color_string)
			(*map)->dots[row][i]->color = ft_atoi_hex(color_string);
		if (!color_string)
			(*map)->dots[row][i]->color = 0xFFFFFF;
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
	line = get_next_line(fd);
	fill_line(map, line, i);
	while (line)
	{
		fill_line(map, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

static char	*get_color(char **splited, int i)
{
	char	*color;

	color = ft_strrchr(splited[i], ',');
	return (color);
}
