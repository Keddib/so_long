/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:10:34 by keddib            #+#    #+#             */
/*   Updated: 2021/09/20 13:15:17 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*cpy;
// 	int		len;
// 	int		i;

// 	len = ft_strlen(s1);
// 	cpy = malloc(sizeof(char) * len + 1);
// 	if (!cpy)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		cpy[i] = s1[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src || !size)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
