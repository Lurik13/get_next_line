/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:40 by lribette          #+#    #+#             */
/*   Updated: 2023/11/10 18:14:08 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*str;

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
	return (str);
}

char    *read_line(int fd)
{
    char    *buffer;
    int     i;

    i = -1;
    buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

int	main(void)
{
	int	fd;
	
	fd = open("text.txt", O_RDONLY);
	printf("%s", read_line(fd));
}