/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:45:59 by lribette          #+#    #+#             */
/*   Updated: 2023/11/11 19:25:16 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(int fd)
{
	static char	*result = NULL;
	char		*buf;

	buf = ft_read_line(fd);
	while (buf != NULL)
	{
		result = ft_strjoin(result, buf);
		free(buf);
		buf = ft_read_line(fd);
	}
	return (result);
}
/*
char	*get_next_line(int fd)
{
	
}*/

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	i = -1;
	fd = open("text.txt", O_RDONLY);
	while (++i < 5)
		printf("%s" ,fill_buffer(fd));
	return(0);
}

/*int	main(void)
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/