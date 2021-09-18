/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:07:45 by keddib            #+#    #+#             */
/*   Updated: 2021/09/18 13:49:19 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	end_game(t_all *all)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = ((all->win.rows / 2) - 1) * TILE_SIZE;
	while (y < ((all->win.rows / 2) - 1) * TILE_SIZE + (TILE_SIZE * 2))
	{
		x = ((all->win.cols / 2) - 1) * TILE_SIZE;
		while (x++ < ((all->win.cols / 2) - 1) * TILE_SIZE + (TILE_SIZE * 2))
			my_mlx_pixel_put(&g_mlx, x, y, all->tex.data[4][i++]);
		y++;
	}
}
