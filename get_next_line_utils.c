/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:34 by lribette          #+#    #+#             */
/*   Updated: 2023/11/14 17:19:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
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

int	ft_strchr(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\n')
	{
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}

/*char	*ft_strdup(char *s, int i)
{
	char	*ptr;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s);
	ptr = malloc((len + 1));
	if (!ptr)
		return (NULL);
	while (s[++i] || i < ft_strchr(s) + 1)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}*/

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