/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:34 by lribette          #+#    #+#             */
/*   Updated: 2023/11/13 18:29:07 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *result, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;
	
	i = -1;
	j = -1;
	str = malloc(ft_strlen(result) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	while (result[++i])
		str[i] = result[i];
	while (buffer[++j])
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	return (str);
}

char	*ft_read_line(int fd, char *result)
{
	char	*buffer;
	int	x;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	x = read(fd, buffer, BUFFER_SIZE);
	if (x <= 0)
		return (NULL);
	result = ft_strjoin(result, buffer);
	free(buffer);
	return (result);
}

int	ft_strchr(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i] != c)
	{
		if (str[i] == '\0')
			return (-i);
		if (str[i] == '\n')
			return (i);
	}
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	printf("%s", ft_read_line(fd, "salut"));
}