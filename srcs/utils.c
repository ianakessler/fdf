/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang@student.42sp.org.br <iaratang>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:22:03 by iaratang@st       #+#    #+#             */
/*   Updated: 2025/11/25 20:32:48 by iaratang@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int count_rows(char *line)
{
    int i;
    int rows;
    int state;

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
