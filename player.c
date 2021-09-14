/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:13:27 by keddib            #+#    #+#             */
/*   Updated: 2021/09/14 18:11:51 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** here I will setup my player and render it, the update also will be here
*/

void setup_player(t_all *all)
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
			if (all->array[i][j] == 'P')
            {
                tile_x = j * TILE_SIZE;
			    tile_y = i * TILE_SIZE;

            }
			j++;
		}
		i++;
	}
    all->fpp.x = tile_x;
    all->fpp.y = tile_y;
}

void update_player(t_all *all)
{
    float new_player_x;
    float new_player_y;

    new_player_x = all->fpp.x + all->fpp.x_direction * WALK_SPEED;
    new_player_y = all->fpp.y + all->fpp.y_direction * WALK_SPEED;
    // if (!is_this_wall(new_player_x, new_player_y, all))
    // {
        all->fpp.x = new_player_x;
        all->fpp.y = new_player_y;
    // }
}
