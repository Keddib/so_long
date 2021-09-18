/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:32:15 by keddib            #+#    #+#             */
/*   Updated: 2021/09/17 15:42:20 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(int n)
{
	if (n == 1)
		printf("SO_LONG NEEDS ONE PARAM\n");
	else if (n == 2)
		printf("NOT .ber\n");
	else if (n == 3)
		printf("MAP ERROR\n");
	exit(1);
}

void	check_suffix(char *s, char *suf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i -= 1;
	while (suf[j])
	{
		if (s[i] == suf[j])
			i--;
		else
			ft_error(2);
		j++;
	}
}

void check_param(char *p, t_all *all)
{
	int fd;

	fd = open(p, O_RDONLY);
	if (fd == -1)
	{
		perror("File");
		exit(1);
	}
	check_suffix(p, "reb.");
	all->fd = fd;
}
