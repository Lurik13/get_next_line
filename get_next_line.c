/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:45:59 by lribette          #+#    #+#             */
/*   Updated: 2023/11/10 17:42:37 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*result;

	result = malloc(BUFFER_SIZE);
	return((char *)read(fd, result, BUFFER_SIZE));
	//return ();
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