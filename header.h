/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 04:58:16 by keddib            #+#    #+#             */
/*   Updated: 2021/09/16 16:13:50 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "constants.h"
# include "mlx.h"

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2, int z);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_exit(int i, t_all *all);
int			ft_close(t_all *all);
void		my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
int			is_this_wall(float x, float y, t_all *all);
void		*load_images(t_all *all);
int			key_pressed(int key, t_all *all);
int			key_released(int key, t_all *all);
void		map_render(t_all *all);
void		setup_player(t_all *all);
void		update_player();
void		render_objects(t_all *all, int x, int y, int tex);
void		check_param(char *p, t_all *all);
void		ft_error(int n);
void		read_file(t_all *all);

#endif
