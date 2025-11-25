/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang@student.42sp.org.br <iaratang>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:33:47 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/11/25 19:59:12 by iaratang@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void free_map(t_map **map)
{
    int i;

    if (!map || !(*map))
        return;

    i = 0;
    while (i < (*map)->heigth)
    {
        free((*map)->map[i]);
        i++;
    }

    free((*map)->map);
    free(*map);
    *map = NULL;
}

void free_splited(char **splited, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(splited[i]);
        i++;
    }
    free(splited);
    splited = NULL;
}
