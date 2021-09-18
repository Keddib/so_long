/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:31:23 by keddib            #+#    #+#             */
/*   Updated: 2021/09/18 16:16:27 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			free(line);
			return (0);
		}
		i++;
	}
	return (i);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
		{
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

int	middle_line(char *line, int size)
{
	int	i;

	i = 1;
	if ((int)ft_strlen(line) == size)
	{
		if (line[0] == '1' && line[size - 1] == '1')
		{
			if (check_line(line))
				return (0);
		}
		else
		{
			free(line);
			return (0);
		}
		return (1);
	}
	free(line);
	return (0);
}

void	delete_last_char(char *line)
{
	while (*line)
		line++;
	line--;
	*line = 0x00;
}

int	read_file(t_all *all)
{
	int		i;
	char	*line;

	i = 0;
	init_array(&all->map, TILE_SIZE);
	while (get_next_line(all->fd, &line))
	{
		delete_last_char(line);
		if (i == 0)
		{
			all->win.cols = first_line(line);
			if (all->win.cols == 0)
				return (0);
		}
		else
			if (!middle_line(line, all->win.cols))
				return (0);
		add_line_to_array(&all->map, line);
		free(line);
		i++;
	}
	all->win.rows = i;
	free(line);
	return (1);
}
