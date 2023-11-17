/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:54 by lribette          #+#    #+#             */
/*   Updated: 2023/11/17 18:46:32 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *src, size_t n)
{
	char	*dest;

	dest = src;
	while (n)
	{
		*dest++ = 0;
		n--;
	}
}

char	*ft_right_charr(char *result, int *isread)
{
	int	x;
	int	i;
	//char	*tmp;

	if (*isread == -1)
		return (NULL);
	i = 0;
	x = ft_strchr(result) + 1;
	result = ft_strjoin("", result + x);
	while (result[x])
	{
		tmp[i] = result[x];
		i++;
		x++;
	}
	ft_bzero(result, ft_strlen(result, 0));
	i = -1;
	while (tmp[++i])
		result[i] = tmp[i];
	free(tmp);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result = NULL;
	char	*returned_line;
	int	isread;

	isread = 1;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (0);
	result = ft_read_line(fd, result, &isread);
	while (ft_strchr(result) == -1 && isread != -1)
		result = ft_read_line(fd, result, &isread);
	returned_line = ft_strdup(result, ft_strchr(result), 0);
	result = ft_right_charr(result, &isread);
	if (returned_line[0] == '\n' && returned_line[1])
		return ("\n");
	if (isread == -1)
		return (NULL);
	return (returned_line);
}

//return (null) ?
//comptabiliser \n

int	main(void)
{
	int fd;
	int i;
	char *result;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	while (i < 6)
	{
		result = get_next_line(fd);
		printf("%s", result);
		i++;
	}
	free(result);
	return (0);
}