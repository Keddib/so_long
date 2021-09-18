/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:13:27 by keddib            #+#    #+#             */
/*   Updated: 2021/09/18 13:54:39 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*
** here I will render my player, the update also will be here
*/

void	render_objects(t_all *all, int x, int y, int tex)
{
	int	p;
	int	p1;
	int	i;

	p1 = y;
	p = x;
	i = 0;
	while (y < p1 + TILE_SIZE)
	{
		x = p;
		while (x++ < p + TILE_SIZE)
		{
			if (all->tex.data[tex][i] != all->tex.data[tex][0])
				my_mlx_pixel_put(&g_mlx, x, y, all->tex.data[tex][i]);
			i++;
		}
		y++;
	}
}

int	is_this_wall(float x, float y, t_all *all)
{
	int	index_x;
	int	index_y;

	index_x = floor((x + 4) / TILE_SIZE);
	index_y = floor((y + 4) / TILE_SIZE);
	if (x < 0 || x > all->win.width || y < 0 || y > all->win.height)
		return (1);
	if (index_y >= all->win.rows || index_x >= all->win.cols)
		return (1);
	else if (all->map.a[(index_y * all->win.cols) + index_x] == '1')
		return (1);
	else if (all->map.a[(index_y * all->win.cols) + index_x] == 'E')
	{
		if (all->fpp.cols != 0)
			return (1);
		all->win.finish = 1;
	}
	return (0);
}

int	is_this_colls(float x, float y, t_all *all)
{
	int	index_x;
	int	index_y;

	index_x = floor((x + 4) / TILE_SIZE);
	index_y = floor((y + 4) / TILE_SIZE);
	if (all->map.a[(index_y * all->win.cols) + index_x] == 'C')
	{
		all->map.a[(index_y * all->win.cols) + index_x] = '0';
		all->fpp.cols -= 1;
	}
	return (0);
}

void	update_player(t_all *all)
{
	float	new_player_x;
	float	new_player_y;

	new_player_x = all->fpp.x + all->fpp.x_direction * TILE_SIZE;
	new_player_y = all->fpp.y + all->fpp.y_direction * TILE_SIZE;
	if (!is_this_wall(new_player_x, new_player_y, all))
	{
		all->fpp.x = new_player_x;
		all->fpp.y = new_player_y;
		if (all->fpp.x_direction || all->fpp.y_direction)
			all->fpp.steps += 1;
	}
	is_this_colls(all->fpp.x, all->fpp.y, all);
	printf("\rSteps : %d |", (int)all->fpp.steps);
	fflush(stdout);
}
