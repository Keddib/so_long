/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:38:35 by keddib            #+#    #+#             */
/*   Updated: 2021/09/18 13:53:37 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_space(int x, int y, int color)
{
	int	p;
	int	p1;

	p1 = y;
	p = x;
	while (y <= p1 + TILE_SIZE)
	{
		x = p;
		while (x++ <= p + TILE_SIZE)
			my_mlx_pixel_put(&g_mlx, x, y, color);
		y++;
	}
}

void	render_wall(t_all *all, int x, int y, int tex)
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
			my_mlx_pixel_put(&g_mlx, x, y, all->tex.data[tex][i++]);
		y++;
	}
}

void	map_render(t_all *all)
{
	int	i;
	int	tile_x;
	int	tile_y;

	i = 0;
	tile_y = 0;
	tile_x = 0;
	while (all->map.a[i])
	{
		tile_x = i % all->win.cols;
		tile_y = i / all->win.cols;
		tile_x = tile_x * TILE_SIZE;
		tile_y = tile_y * TILE_SIZE;
		free_space(tile_x, tile_y, 15335423);
		if (all->map.a[i] == '1')
			render_wall(all, tile_x, tile_y, 0);
		else if (all->map.a[i] == 'E')
			render_wall(all, tile_x, tile_y, 2);
		else if (all->map.a[i] == 'C')
			render_objects(all, tile_x, tile_y, 1);
		i++;
	}
}
