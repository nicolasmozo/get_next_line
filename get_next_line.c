/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omozo-av <omozo-av@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:59:25 by omozo-av          #+#    #+#             */
/*   Updated: 2022/12/20 22:06:31 by omozo-av         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_line(char *line_read)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_read[i])
		return (NULL);
	while (line_read[i] && line_read[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line_read[i] && line_read[i] != '\n')
	{
		str[i] = line_read[i];
		i++;
	}
	if (line_read[i] == '\n')
	{
		str[i] = line_read[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_remaining(char *line_read)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line_read[i] && line_read[i] != '\n')
		i++;
	if (!line_read[i])
	{
		free(line_read);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line_read) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line_read[i])
		str[j++] = line_read[i++];
	str[j] = '\0';
	free(line_read);
	return (str);
}

char	*reading_line(int fd, char *line_read)
{
	char	*temp;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line_read, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		line_read = ft_strjoin(line_read, temp);
	}
	free(temp);
	return (line_read);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_read = reading_line(fd, line_read);
	if (!line_read)
		return (NULL);
	line = clean_line(line_read);
	line_read = get_remaining(line_read);
	return (line);
}
/*
#include <stdio.h>
#include <unistd.h>
int main()
{
    char *buffer;
    int fd = open("test.txt", O_RDONLY);
    int i = 1;
	while (i < 7)
	{
		buffer = get_next_line(fd);
		printf("line [%02d]: %s\n", i, buffer);
		//free(buffer);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
    //buffer = get_next_line(fd);
    //printf("%s",buffer);
}
*/
