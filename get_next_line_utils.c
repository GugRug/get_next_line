/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:58:18 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/20 10:13:52 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dest == 0 || src == 0 || dest == src)
		return (0);
	while (src[j])
		j++;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

int		ft_strchr_bn(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	i = -1;
	while (++i < nmemb * size)
		p[i] = '\0';
	return (p);
}
