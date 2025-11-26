/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:35:37 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/11/26 17:18:03 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_map_height(t_map **map, char *file_name)
{
	int		total_lines;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	total_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		total_lines++;
		free(line);
	}
	if ((*map))
		(*map)->heigth = total_lines;
	close(fd);
}

static void	set_map_width(t_map **map, char *file_name)
{
	int	total_rows;
	int	fd;
	char	*line;
	char	**splited_line;
	char	*trim_line;

	fd = open(file_name, O_RDONLY);
	total_rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		trim_line = ft_strtrim(line, " \n\t");
		splited_line = ft_split(trim_line, ' ');
		if (!splited_line || !trim_line)
			break;
		free(trim_line);
		while (splited_line[total_rows])
			total_rows++;
		free_splited(splited_line);
	}
	if ((*map))
		(*map)->width = total_rows;
	close(fd);
}

void	malloc_map(t_map **map, char *file_name)
{
	int	i;

	i = 0;
	set_map_height(map, file_name);
	set_map_width(map, file_name);
	(*map)->map = malloc(sizeof(int *) * (*map)->heigth);
	if (!(*map)->map)
	{
		ft_putstr_fd("Error allocting map, exiting...\n", 1);
		exit(1);
	}
	while (i < (*map)->heigth)
	{
		(*map)->map[i] = malloc(sizeof(int) * (*map)->width);
		if (!(*map)->map[i])
		{
			while(--i >= 0)
				free((*map)->map[i]);
			free((*map)->map);
			return ;
		}
		i++;
	}
}
