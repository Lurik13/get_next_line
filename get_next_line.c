/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:54 by lribette          #+#    #+#             */
/*   Updated: 2023/11/16 16:51:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*tmp;

	if (*isread == -1)
		return (NULL);
	i = 0;
	x = ft_strchr(result) + 1;
	tmp = ft_strdup(result, ft_strlen(result, 0) - x, x);
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
	static char	*result;
	char	*returned_line;
	int	isread;

	isread = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = ft_read_line(fd, result, &isread);
	while (ft_strchr(result) == -1 && isread != -1)
	{
		result = ft_read_line(fd, result, &isread);
		/*if ((ft_strlen(result, 0) % BUFFER_SIZE) != 0)
			break ;*/
	}
	returned_line = ft_strdup(result, ft_strchr(result), 0);
	result = ft_right_charr(result, &isread);
	return (returned_line);
}

//retourne chaine jusqu'au \n inclus
//static = chaine de droite
//comptabiliser la ligne sans \n
//comptabiliser ancienne chaine
//return (null) ?

int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	while (i < 5)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	free
	return (0);
}