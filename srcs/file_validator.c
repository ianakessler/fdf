/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:34:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/24 17:44:12 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	validate_fd(int argc, int fd);
static void	file_name_validator(char *file_name);

static void	file_name_validator(char *file_name)
{
	char	*file_extension;
	int		is_fdf;

	file_extension = ft_strrchr(file_name, '.');
	is_fdf = ft_strncmp(".fdf", file_extension, 4);
	if (is_fdf != 0)
	{
		ft_putstr_fd("Please select a valid .fdf file.\n", 1);
		exit(1);
	}
}

static void	validate_fd(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments.\n", 1);
		exit(1);
	}
	if (fd < 0)
	{
		ft_putstr_fd("Please select a valid map file.\n", 1);
		exit(1);
	}
}

void	parse_map(int argc, char	*file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	validate_fd(argc, fd);
	file_name_validator(file);
	close(fd);
}
