/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:30:56 by keddib            #+#    #+#             */
/*   Updated: 2021/09/17 15:38:51 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void init_array(t_array *a, size_t size)
{
	a->a = (char *)malloc(size * sizeof(char));
	a->used = 0;
	a->size = size;
}

void insert_array(t_array *a, char element)
{
	char *tmp;

	if (a->used == a->size)
	{
		a->size *= 2;
		tmp = a->a;
		a->a = (char *)malloc(a->size * sizeof(char));
		ft_strlcpy(a->a, tmp, a->used + 1);
		free(tmp);
	}
	a->a[a->used++] = element;
}

void	add_line_to_array(t_array *a, char *line)
{
	int i;

	i = 0;
	while (line[i])
		insert_array(a, line[i++]);
}

void free_array(t_array *a)
{
	free(a->a);
	a->a = NULL;
	a->used = a->size = 0;
}
