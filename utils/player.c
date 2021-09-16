/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:13:27 by keddib            #+#    #+#             */
/*   Updated: 2021/09/16 17:48:36 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*
** here I will setup my player and render it, the update also will be here
*/

void setup_player(t_all *all)
{
	int i = 0;
	int j = 0;

	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			if (all->array[i][j] == 'P')
			{
				all->fpp.x = j * TILE_SIZE;
				all->fpp.y = i * TILE_SIZE;
				all->fpp.steps = 0;
				printf("\rSteps : %d |", (int)all->fpp.steps);
				fflush(stdout);
			}
			j++;
		}
		i++;
	}
}

int is_this_wall(float x, float y, t_all *all)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HIEGHT)
		return 1;
	int index_x;
	int index_y;
	index_x = floor((x + 4) / TILE_SIZE);
	index_y = floor((y + 4) / TILE_SIZE);
	if (index_y >= MAP_NUM_ROWS  || index_x >= MAP_NUM_COLS)
		return (1);
	else if (all->array[index_y][index_x] == '1')
		return (1);
	index_x = floor(((x - 4)+TILE_SIZE) / TILE_SIZE);
	index_y = floor(((y - 4)+TILE_SIZE) / TILE_SIZE);
	if (index_y >= MAP_NUM_ROWS  || index_x >= MAP_NUM_COLS)
		return (1);
	if (all->array[index_y][index_x] == '1')
		return (1);
	return (0);
}

void update_player(t_all *all)
{
	float new_player_x;
	float new_player_y;

	new_player_x = all->fpp.x + all->fpp.x_direction * TILE_SIZE;
	new_player_y = all->fpp.y + all->fpp.y_direction * TILE_SIZE;
	if (!is_this_wall(new_player_x, new_player_y, all))
	{
		all->fpp.x = new_player_x;
		all->fpp.y = new_player_y;
		if (all->fpp.x_direction || all->fpp.y_direction)
		{
			all->fpp.steps += 1;
			printf("\rSteps : %d |", (int)all->fpp.steps);
			fflush(stdout);
		}

	}
}
