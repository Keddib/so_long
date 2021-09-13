/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 04:58:16 by keddib            #+#    #+#             */
/*   Updated: 2021/09/13 17:21:44 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "constants.h"
# include "mlx.h"

int		key_pressed(int key, t_all *all);
int		key_released(int key, t_all *all);
int		ft_exit(int i, t_all *all);
int		ft_close(t_all *all);
void	map_render(t_all *all);
void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
int		is_this_wall(float x, float y, t_all *all);
void	map_render(t_all *all);
void	*load_images(t_all *all);

#endif
