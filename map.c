/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:38:35 by keddib            #+#    #+#             */
/*   Updated: 2021/09/14 15:59:42 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void free_space(int x, int y, int color)
{
	int p, p1;
	p1 = y;
	p = x;

	while (y <= p1 + TILE_SIZE)
	{
		x = p;
		while (x++ <= p + TILE_SIZE)
			my_mlx_pixel_put(&mlx, x, y, color);
		y++;
	}
}

int is_this_wall(float x, float y, t_all *all)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HIEGHT)
		return 1;
	int index_x;
	int index_y;
	index_x = floor(x / TILE_SIZE);
	index_y = floor(y / TILE_SIZE);
	if (index_y >= MAP_NUM_COLS  || index_x >= MAP_NUM_ROWS)
		return 1;
	if (all->array[index_y][index_x] == '1')
		return 1;
	return 0;
}

void	render_objects(t_all *all, int x, int y, int tex)
{
	int p;
	int p1;
	int i;

	p1 = y;
	p = x;
	i = 0;
	while (y < p1 + TILE_SIZE)
	{
		x = p;
		while (x++ < p + TILE_SIZE)
		{
			if (all->tex.data[tex][i] != all->tex.data[tex][0])
				my_mlx_pixel_put(&mlx, x, y, all->tex.data[tex][i]);
			else
				my_mlx_pixel_put(&mlx, x, y, 15335423);
			i++;
		}
		y++;
	}

}

void	render_wall(t_all *all, int x, int y, int tex)
{

	int p;
	int p1;
	int i;

	p1 = y;
	p = x;
	i = 0;
	while (y < p1 + TILE_SIZE)
	{
		x = p;
		while (x++ < p + TILE_SIZE)
			my_mlx_pixel_put(&mlx, x, y, all->tex.data[tex][i++]);
		y++;
	}
}

void map_render(t_all *all)
{
	int i = 0;
	int j = 0;
	int tile_x = 0;
	int tile_y = 0;

	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			if (all->array[i][j] == '1')
				render_wall(all, tile_x, tile_y, 0);
			else if (all->array[i][j] == 'C')
				render_objects(all, tile_x, tile_y, 1);
			else if (all->array[i][j] == 'E')
				render_wall(all, tile_x, tile_y, 2);
			else
				free_space(tile_x, tile_y, 15335423);
			j++;
		}
		i++;
	}
}
