/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 04:44:34 by keddib            #+#    #+#             */
/*   Updated: 2021/09/17 18:10:23 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WALK_SPEED 64
# define INT_MAX 2147483647
# define TILE_SIZE 64


typedef struct	s_data
{
	void	*ptr;
	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_n;
	int		endian;
}				t_data;

typedef struct	s_win
{
	float	width;
	float	height;
	int		rows;
	int		cols;
}				t_win;

typedef struct	s_player
{
	float	x;
	float	y;
	int		x_direction;
	int		y_direction;
	int		found;
	int		steps;
	int		finish;
}				t_player;

typedef struct	s_texture
{
	void			*img;
	unsigned int	*data[4];
	char			*file[4];
}				t_texture;

typedef struct	s_array
{
	char		*a;
	size_t		used;
	size_t		size;
}				t_array;

typedef struct	s_all
{
	t_win		win;
	t_player	fpp;
	t_texture	tex;
	t_array		map;
	int			fd;
}				t_all;

t_data			mlx;

#endif
