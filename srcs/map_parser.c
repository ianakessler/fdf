/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:59 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/24 18:35:59 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


//recebe uma linha (string) e conta quantos numeros tem
int	count_numbers_in_line(char *line)
{
	int	i;
	int	state;
	int	nums;

	i = 0;
	state = 0;
	nums = 0;
	while (line[i])
	{
		if ((line[i] != ' ' && line[i] != '\n' && line[i] != '\t') && !state)
		{
			state = 1;
			nums++;
		}
		if (state && (line[i] == ' ' || line[i] == '\t'))
			state = 0;
		i++;
	}
	return (nums);
}
//le cada linha e retorna a mais longa (numero de colunas da matriz)
int	chars_line_counter(char	*file_name)
{
	char	*line;
	int		len;
	int		chars_in_line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	chars_in_line = 0;
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		chars_in_line = count_numbers_in_line(line);
		free(line);
		len++;
	}
	close(fd);
	return (chars_in_line);
}

int	count_map_rows(char *file_name, t_map **map)
{
	int		total_lines;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	total_lines = 0;
	while(1)
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
	return (total_lines);
}

void	init_map(t_map **map,int lines, char *map_name)
{
	int		fd;
	char	*line;
	char	*raw;
	char	**splited;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	printf("%i\n", fd);
	while (i < lines)
	{
		raw = get_next_line(fd);
		if (!raw)
			break;
		printf("Debugano\n");
		line = ft_strtrim(raw, " \n\t");
		free(raw);
		splited = ft_split(line, ' ');
		fill_map_array(splited, i, map);
		free(line);
		free_splited(splited);
		i++;
	}
}

void	fill_map_array(char **splited, int	line, t_map **map)
{
	int		current_value;
	int		i;
	t_map	*mapa;

	printf("ncjdbjds\n");
	mapa = *map;
	i = 0;
	while (splited[i])
	{
		current_value = ft_atoi(splited[i]);
		printf("%i\n", current_value);
		mapa->map[line][i] = current_value;
		i++;
	}
}


void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
