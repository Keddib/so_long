/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:31:23 by keddib            #+#    #+#             */
/*   Updated: 2021/09/16 18:05:02 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


void	first_line(t_all *all, int l)
{
	int i;

	i = 0;
	printf("%s\n", all->array[l]);
	while (all->array[l][i])
	{
		if (all->array[l][i] != '1')
		{
			while (l >= 0)
				free(all->array[l--]);
			free(all->array);
			ft_error(3);
		}
		i++;
	}
	all->win.cols = i;
}

void	middle_line(t_all *all, int l)
{
	if ((int)ft_strlen(all->array[l]) == all->win.cols)
	{
		if (all->array[l][0] == '1' && all->array[l][all->win.cols - 1] == '1')
			return;
	}
	while (l >= 0)
		free(all->array[l--]);
	free(all->array);
	ft_error(3);
}

void create_map(t_all *all)
{
	int		i;
	char	*line;

	all->win.rows = 0;
	line = malloc(12000 * sizeof(char));
	i = read(all->fd, line, 12000);
	line[i] = 0x00;
	i = 0;
	while (line[i])
		if (line[i++] == '\n')
			all->win.rows += 1;
	free(line);
	all->array = (char **)malloc((MAP_NUM_ROWS + 1)* sizeof(char *));
}

void	read_file(t_all *all)
{
	int		i;

	i = 0;
	create_map(all);
	while (get_next_line(all->fd, &all->array[i]))
	{
		if (i == 0)
			first_line(all, i);
		else
			middle_line(all, i);
		i++;
	}
	i = 0;
	// while (all->array[i])
	// 	printf("%s\n", all->array[i]);
	// free(line);
}
