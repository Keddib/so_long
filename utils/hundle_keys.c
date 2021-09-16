/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:14:17 by keddib            #+#    #+#             */
/*   Updated: 2021/09/16 16:03:02 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		key_pressed(int key, t_all *all)
{
	if (key == 53)
		ft_exit(0, all);
	else if (key == 13)
		all->fpp.y_direction = -1;
	else if (key == 1) // s
		all->fpp.y_direction = +1;
	else if (key == 2) // d
		all->fpp.x_direction = +1;
	else if (key == 0) // a
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

int		ft_exit(int i, t_all *all)
{
	i = 0;
	// int j;

	// j = 0;
	// if (i == 0 || i == 100)
	// {
	// 	// ft_free(all->win.array, all->win.cols);
	// 	if (i == 100)
	// 		exit(0);
	// TODO: DELETE THIS LINE
	all->fd += 0;
	mlx_destroy_image(mlx.ptr, mlx.img);
	mlx_destroy_window(mlx.ptr, mlx.win);
	free(mlx.ptr);
	// }
	// else
	// 	// put message in case of error
	exit(0);
	return (0);
}

int		ft_close(t_all *all)
{
	ft_exit(0, all);
	return (0);
}
