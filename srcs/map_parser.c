/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:59 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/19 17:45:11 by iaratang         ###   ########.fr       */
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
int	chars_line_counter(int fd)
{
	char	*line;
	int		len;
	int		max_chars_in_line;
	int		chars_in_line;

	chars_in_line = 0;
	max_chars_in_line = 0;
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		chars_in_line= count_numbers_in_line(line);
		max_chars_in_line = chars_in_line;
		if (chars_in_line != max_chars_in_line)
		{
			ft_putstr_fd("Map is not a retangle\n", 1);
			exit(1);
		}
		free(line);
		len++;
	}
	return (max_chars_in_line);
}

int	count_map_rows(int fd)
{
	int		total_lines;
	char	*line;

	total_lines = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		total_lines++;
		free(line);
	}
	free(line);
	return (total_lines);
}
