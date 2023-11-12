/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:34 by lribette          #+#    #+#             */
/*   Updated: 2023/11/12 18:51:21 by lribette         ###   ########.fr       */
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

char	*ft_read_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t x;

	x = read(fd, buffer, BUFFER_SIZE);
	if (x == 0)
		return (NULL);
	return (buffer);
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
	printf("%s", ft_read_line(fd));
}