/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omozo-av <omozo-av@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:21:50 by omozo-av          #+#    #+#             */
/*   Updated: 2022/12/20 22:09:27 by omozo-av         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	else
	{
		while (i < n)
		{
			((char *)str)[i] = 0;
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (!count || !size)
	{
		ptr = malloc(sizeof(char));
		ptr[0] = '\0';
		return (ptr);
	}
	if (count > SIZE_MAX / size)
		return (0);
	ptr = malloc (count * size);
	if (!(ptr))
		return (0);
	ft_bzero (ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		s1 = ft_calloc (1, 1);
	if (!s1 || !s2)
		return (0);
	join = malloc (sizeof(char) * ((ft_strlen (s1) + ft_strlen (s2)) + 1));
	if (!(join))
		return (0);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
