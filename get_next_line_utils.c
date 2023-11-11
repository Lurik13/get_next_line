/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:40 by lribette          #+#    #+#             */
/*   Updated: 2023/11/11 19:27:37 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = -1;
	j = -1;
	str = malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char    *ft_read_line(int fd)
{	
	char    *buffer;
	int     i;
	ssize_t x;
	
	i = -1;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	x = read(fd, buffer, BUFFER_SIZE);
	if (x == -1)
		return (NULL);
	return (buffer);
}
/*
int	main(void)
{
	int	fd;
	
	fd = open("text.txt", O_RDONLY);
	printf("%s", ft_read_line(fd));
}*/