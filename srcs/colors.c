/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:50:48 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/26 19:46:16 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_color_in_line(char *line);
void	fill_color_map_line(t_map **map, char *line, int row);

void	check_colors(char *file_name, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	int		color;

	color = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (i < map->heigth)
	{
		line = get_next_line(fd);
		color = check_color_in_line(line);
		free(line);
		i++;
	}
	if (color > 0)
		printf("HAVE COLORS!!\n");
	if (color == 0)
		printf("DONT HAVE COLORS!!\n");
	close(fd);
}

static int	check_color_in_line(char *line)
{
	char	**splited;
	char	*trim;
	char	*color;
	int		i;

	i = 0;
	trim = ft_strtrim(line, " \n\t");
	splited = ft_split(trim, ' ');
	free(trim);
	while (splited[i])
	{
		color = ft_strchr(splited[i], ',');
		if (color)
		{
			printf("%s\t", color + 1);
			free_splited(splited);
			return (1);
		}
		i++;
	}
	free_splited(splited);
	return (0);
}


void	malloc_colors_array(t_map **map)
{
	int	i;

	i = 0;
	(*map)->colors = malloc(sizeof(int *) * (*map)->heigth);
	if (!(*map)->colors)
		return ;
	while (i < (*map)->heigth)
	{
		(*map)->colors[i] = malloc(sizeof (int) * (*map)->width);
		if (!(*map)->colors[i])
		{
			while(--i >= 0)
				free((*map)->colors[i]);
			free((*map)->colors);
			return ;
		}
	}
}

void	fill_colors_map(t_map **map, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < (*map)->heigth)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		fill_color_map_line(map, line, i);
		free(line);
	}
	close(fd);
}

void	fill_color_map_line(t_map **map, char *line, int row)
{
	char	**splited;
	char	*hex_value;
	int		num_hex;
	int		i;

	i = 0;
	splited = ft_split(line, ' ');
	while (splited[i])
	{
		hex_value = ft_strchr(splited[i], ',') + 1;
		if (hex_value)
		{
			num_hex = ft_atoi_hex(hex_value);
			(*map)->colors[row][i] = num_hex;
		}
		else
			(*map)->colors[row][i] = 0;
		i++;
	}
	free_splited(splited);
}
