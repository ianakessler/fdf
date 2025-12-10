/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:22:03 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/12/10 17:49:24 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_rows(char *line)
{
	int	i;
	int	rows;
	int	state;

	i = 0;
	state = 0;
	rows = 0;
	while (line[i])
	{
		if (!state && line[i] != ' ')
		{
			state = 1;
			rows++;
		}
		if (state && line[i] == ' ')
		{
			state = 0;
		}
		i++;
	}
	return (rows);
}

int	ft_atoi_hex(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			num += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			num += str[i] - 'a' + 10;
		i++;
	}
	return (num);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

char	**trim_and_split(char *line)
{
	char	*trimmed;
	char	**splited;

	trimmed = ft_strtrim(line, " \n\t");
	splited = ft_split(trimmed, ' ');
	free(trimmed);
	return (splited);
}
