/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:13:27 by keddib            #+#    #+#             */
/*   Updated: 2021/09/13 18:15:06 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** here I will setup my player and render it, the update also will be here
*/

void setup_player()
{
    player.x = window.width / 2;
    player.y = window.height / 2;
    player.radius = 10;
    player.rotation_angle = M_PI / 2;
    player.walk_direction = 0;
    player.side_direction = 0;
    player.turn_direction = 0;
    player.move_speed = 0;
}

void update_player()
{
    float new_player_x;
    float new_player_y;
    float move_step;
    float side_step;

    player.rotation_angle += player.turn_direction * TURN_SPEED;
    move_step = player.walk_direction * (WALK_SPEED + player.move_speed);
    new_player_x = player.x + cos(player.rotation_angle) * move_step;
    new_player_y = player.y + sin(player.rotation_angle) * move_step;
    side_step = player.side_direction * WALK_SPEED;
    new_player_x += cos(player.rotation_angle + (90 * RADIUN)) * side_step;
    new_player_y += sin(player.rotation_angle + (90 * RADIUN)) * side_step;
    if (!is_this_wall(new_player_x, new_player_y))
    {
        player.x = new_player_x;
        player.y = new_player_y;
    }
}



void render_player(int x, int y)
{
    my_mlx_pixel_put(&mlx, x, y, 0xffffff);
}
