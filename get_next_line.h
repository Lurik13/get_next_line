/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:29:51 by lribette          #+#    #+#             */
/*   Updated: 2023/11/16 16:44:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int	ft_strlen(char *str, int i);
char	*ft_strjoin(char *result, char *buffer);
char	*ft_read_line(int fd, char *result, int *isread);
int	ft_strchr(char *str);
char	*ft_strdup(char *s, int len, int start);
void	ft_bzero(void *src, size_t n);
char	*ft_right_charr(char *result, int *isread);
char *get_next_line(int fd);

#endif