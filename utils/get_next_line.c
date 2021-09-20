/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:09:18 by keddib            #+#    #+#             */
/*   Updated: 2021/09/20 14:25:11 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_next_line(int fd, char **line)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(2);
	*line = (char *)malloc(1);
	if (!line || !buff)
		return (-1);
	*line[0] = 0x00;
	i = read(fd, buff, 1);
	while (i > 0)
	{
		if (buff[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buff[0]);
		i = read(fd, buff, 1);
	}
	free(buff);
	buff = NULL;
	return (i);
}
