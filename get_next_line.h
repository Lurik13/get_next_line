/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:29:51 by lribette          #+#    #+#             */
/*   Updated: 2023/11/10 18:03:04 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_H
# define get_next_line_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif