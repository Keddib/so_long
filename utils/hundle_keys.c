/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:14:17 by keddib            #+#    #+#             */
/*   Updated: 2021/09/17 16:31:56 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		key_pressed(int key, t_all *all)
{
	if (key == 53)
		ft_exit(all);
	else if (key == 13)
		all->fpp.y_direction = -1;
	else if (key == 1)
		all->fpp.y_direction = +1;
	else if (key == 2)
		all->fpp.x_direction = +1;
	else if (key == 0)
		all->fpp.x_direction = -1;
	return (0);
}

int		key_released(int key, t_all *all)
{
	key = 0;
	all->fpp.y_direction = 0;
	all->fpp.x_direction = 0;
	return (0);
}

void	ft_exit(t_all *all)
{
	free_array(&all->map);
	mlx_destroy_image(mlx.ptr, mlx.img);
	mlx_destroy_window(mlx.ptr, mlx.win);
	free(mlx.ptr);
	exit(0);
}

int		ft_close(t_all *all)
{
	ft_exit(all);
	return (0);
}
