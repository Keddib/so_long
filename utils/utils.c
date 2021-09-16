/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:16:20 by keddib            #+#    #+#             */
/*   Updated: 2021/09/16 16:12:34 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_n + x * (mlx->bpp / 8));
	if (x < WIN_WIDTH && x >= 0 && y < WIN_WIDTH && y >= 0)
		*(unsigned int *)dst = color;
}

void	*load_images(t_all *all)
{
	int i;
	int t;

	i = 0;
	all->tex.file[0] = "./textures/wall.xpm";
	all->tex.file[1] = "./textures/collectible.xpm";
	all->tex.file[2] = "./textures/exit.xpm";
	all->tex.file[3] = "./textures/player.xpm";
	while (i < 4)
	{
		all->tex.img = mlx_xpm_file_to_image(mlx.ptr,
				all->tex.file[i], &t, &t);
		all->tex.data[i] = (unsigned int *)mlx_get_data_addr(
				all->tex.img,
				&mlx.bpp,
				&mlx.line_n,
				&mlx.endian);
		free(all->tex.img);
		i++;
	}
	return (NULL);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}