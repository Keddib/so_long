/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:17:09 by keddib            #+#    #+#             */
/*   Updated: 2021/09/18 16:11:43 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initializer(t_all *all)
{
	int	i;

	i = 0;
	all->fpp.steps = 0;
	all->fpp.cols = 0;
	all->win.finish = 0;
	all->win.width = (all->win.cols * TILE_SIZE);
	all->win.height = (all->win.rows * TILE_SIZE);
	if (all->win.width > 2560 || all->win.height > 1440)
	{
		free_array(&all->map);
		ft_error(4);
	}
	while (i < all->win.cols * all->win.rows)
	{
		if (all->map.a[i] == 'P')
		{
			all->fpp.x = (i % all->win.cols) * TILE_SIZE;
			all->fpp.y = (i / all->win.cols) * TILE_SIZE;
		}
		if (all->map.a[i] == 'C')
			all->fpp.cols += 1;
		i++;
	}
}

int	update(t_all *all)
{
	if (all->win.finish)
		end_game(all);
	else
	{
		map_render(all);
		update_player(all);
		render_objects(all, all->fpp.x, all->fpp.y, 3);
		all->fpp.y_direction = 0;
		all->fpp.x_direction = 0;
	}
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}

void	setup(t_all *all)
{
	if (!read_file(all) || check_dup(all->map.a, 'P')
		|| check_dup(all->map.a, 'E'))
	{
		free_array(&all->map);
		ft_error(3);
	}
	initializer(all);
	g_mlx.ptr = mlx_init();
	load_images(all);
	g_mlx.win = mlx_new_window(g_mlx.ptr,
			all->win.width, all->win.height, "SL");
	g_mlx.img = mlx_new_image(g_mlx.ptr, all->win.width, all->win.width);
	g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bpp, &g_mlx.line_n,
			&g_mlx.endian);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		ft_error(1);
	else
		check_param(argv[1], &all);
	setup(&all);
	mlx_hook(g_mlx.win, 2, 0, key_pressed, &all);
	mlx_hook(g_mlx.win, 3, 0, key_released, &all);
	mlx_hook(g_mlx.win, 17, 0, ft_close, &all);
	mlx_loop_hook(g_mlx.ptr, update, &all);
	mlx_loop(g_mlx.ptr);
	return (0);
}
