/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:38:35 by keddib            #+#    #+#             */
/*   Updated: 2021/09/13 18:11:40 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_square(int x, int y, int color)
{
	int p, p1;
	p1 = y;
	p = x;

	while (y < p1 + TILE_SIZE)
	{
		x = p;
		while (x < p + TILE_SIZE)
		{
			my_mlx_pixel_put(&mlx, x, y, color);
			x++;
		}
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

void map_render(t_all *all)
{
	int i = 0;
	int j = 0;
	int tile_x = 0;
	int tile_y = 0;
	int color;

	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			if (all->array[i][j] == '1')
				color = 0xfff;
			else
				color = 15335423;
			ft_square(tile_x, tile_y, color);
			j++;
		}
		i++;
	}
}
