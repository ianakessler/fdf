/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:56:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/17 20:00:39 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);


#endif
