/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:37:54 by lribette          #+#    #+#             */
/*   Updated: 2023/11/14 16:19:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*result = NULL;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	result = ft_read_line(fd, result);
	while (ft_strchr(result) == -1 && ft_read_line(fd,result) != NULL)
	{
		result = ft_read_line(fd, result);
		if ((ft_strlen(result) % BUFFER_SIZE) + 1 != 0)
			break ;
	}
	
}

//retourne chaine jusqu'au \n inclus
//static = chaine de droite