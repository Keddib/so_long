/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 04:44:34 by keddib            #+#    #+#             */
/*   Updated: 2021/09/13 17:22:08 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WALK_SPEED 5
# define TURN_SPEED (3 * RADIUN)
# define FOV_ANGLE (60 * RADIUN)
# define INT_MAX 2147483647
# define TILE_SIZE 64
# define MAP_NUM_ROWS 7
# define MAP_NUM_COLS 21
# define WIN_WIDTH	(TILE_SIZE * MAP_NUM_COLS)
# define WIN_HIEGHT	(TILE_SIZE * MAP_NUM_ROWS)

typedef	struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;


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
	float	half_win;
	float	look;
	float	proj_plane;
	int		rows;
	int		cols;
	char	**array;
	char	chr;
}				t_win;

typedef struct	s_player
{
	float	x;
	float	y;
	float	rotation_angle;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
}				t_player;

typedef struct	s_texture
{
	void			*img;
	unsigned int	*data[4];
	char			*file[4];
	int				width;
	int				height;
	int				color[2];
}				t_texture;

typedef struct	s_file
{
	int		map_found;
	int		counter;
	int		res;
}				t_file;

typedef struct	s_all
{
	t_win		win;
	t_player	fpp;
	t_file		file;
	t_texture	tex;
	t_rgb		rgb;
	char		*param1;
	char		**array;
}				t_all;

t_data			mlx;

#endif
