/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang@student.42sp.org.br <iaratang>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:34:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/25 20:30:01 by iaratang@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void    validate_file_name(char *file_name)
{
    char    *file_extension;

    file_extension = ft_strrchr(file_name, '.');
    if (!file_extension || (ft_strncmp(file_extension, ".fdf", 4) != 0))
    {
        ft_putstr_fd("File extension must be .fdf\n", 1);
        exit(1);
    }
}

static void    validate_file_descriptor(char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error opening file descriptor, exiting...\n", 1);
        exit(1);
    }
    close(fd);
}

void    check_map_format(char *file_name)
{
    int fd;
    char    *line;
    char    *trim;
    int rows;
    int compare_rows;

    fd = open(file_name, O_RDONLY);
    rows = 0;
    compare_rows = 0;
    while ((line = get_next_line(fd)))
    {
        trim = ft_strtrim(line, " \n\t");
        free(line);
        rows = count_rows(trim);
        if (compare_rows == 0)
            compare_rows = rows;
        if (compare_rows != 0 && (compare_rows != rows))
        {
            ft_putstr_fd("Map must be a rectangle, exiting...\n", 1);
            exit(1);
        }
    }
}

void	file_validator(char *file_name)
{
	validate_file_name(file_name);
	validate_file_descriptor(file_name);
    check_map_format(file_name);
}