/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:17:09 by keddib            #+#    #+#             */
/*   Updated: 2021/09/14 16:30:10 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initializer(t_all *all)
{
	char *map = "1111111111111111111111000000000000000000011000C000CC00000P00001100000000111100000001111000000011000C000011E0000000001C00000001111111111111111111111";
	int i, j, x;

	all->array = (char **)malloc((MAP_NUM_ROWS + 1)* sizeof(char *));
	x = 0;
	for(i=0; i < MAP_NUM_ROWS; i++)
	{
		all->array[i] = (char *)malloc(MAP_NUM_COLS + 1);
		for (j=0; j < MAP_NUM_COLS; j++)
		{
			all->array[i][j] = map[x];
			x++;
		}
		all->array[i][j] = 0x00;
	}
	all->array[i] = NULL;
}



int	update(t_all *all)
{
	map_render(all);
	// update_player();
	//render_player(all->fpp.x, all->dpp.y);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	return (0);
}

void	setup(t_all *all)
{
	read_file(argv[1], all);
	mlx.ptr = mlx_init();
	initializer(all);
	load_images(all);
	setup_player(all);
	mlx.win = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HIEGHT, "SoLong");
	mlx.img = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HIEGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_n, &mlx.endian);
}


int main()
{
	t_all all;

	if (argc != 2)
		return (0);
	else
		check_param(argv[1]);
	setup(&all);
	mlx_loop_hook(mlx.ptr, update, &all);
	mlx_hook(mlx.win, 2, 1L << 0, key_pressed, &all);
	mlx_hook(mlx.win, 3, (1L << 1), key_released, &all);
	mlx_hook(mlx.win, 17, 0, ft_close, &all);
	mlx_loop(mlx.ptr);
	return(0);
}
