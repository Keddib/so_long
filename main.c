/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:17:09 by keddib            #+#    #+#             */
/*   Updated: 2021/09/17 18:22:00 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initializer(t_all *all)
{
	int	i;

	all->win.width = (all->win.cols * TILE_SIZE);
	all->win.height = (all->win.rows * TILE_SIZE);
	i = 0;
	all->fpp.found = 0;
	all->fpp.steps = 0;
	all->fpp.finish = 0;
	while ( i < all->win.cols * all->win.rows)
	{
		if (all->map.a[i] == 'P')
		{
			all->fpp.found = 1;
			all->fpp.x = (i % all->win.cols) * TILE_SIZE;
			all->fpp.y = (i / all->win.cols) * TILE_SIZE;
		}
		i++;
	}
	// todo cols positions
}

int	update(t_all *all)
{
	map_render(all);
	update_player(all);
	render_objects(all, all->fpp.x, all->fpp.y, 3 + all->fpp.finish);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	all->fpp.y_direction = 0;
	all->fpp.x_direction = 0;
	return (0);
}

void	setup(t_all *all)
{
	if (!read_file(all))
	{
		free_array(&all->map);
		ft_error(3);
	}
	mlx.ptr = mlx_init();
	initializer(all);
	load_images(all);
	mlx.win = mlx_new_window(mlx.ptr, all->win.width, all->win.height, "SoLong");
	mlx.img = mlx_new_image(mlx.ptr, all->win.width, all->win.width);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_n, &mlx.endian);
}


int main(int argc, char **argv)
{
	t_all all;

	if (argc != 2)
		ft_error(1);
	else
	 	check_param(argv[1], &all);
	setup(&all);
	mlx_hook(mlx.win, 2, 0, key_pressed, &all);
	mlx_hook(mlx.win, 3, 0, key_released, &all);
	mlx_hook(mlx.win, 17, 0, ft_close, &all);
	mlx_loop_hook(mlx.ptr, update, &all);
	mlx_loop(mlx.ptr);
	return(0);
}
