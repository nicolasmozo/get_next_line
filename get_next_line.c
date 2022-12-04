/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omozo-av <omozo-av@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:59:25 by omozo-av          #+#    #+#             */
/*   Updated: 2022/12/04 00:08:28 by omozo-av         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *line_read)
{
    char *temp;
    int bytes_read;
    
    temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
    bytes_read = 1;
    while(!ft_strchr(line_read, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(temp);
            return NULL;
        }
        temp[bytes_read] = '\0';
        line_read = ft_strjoin(line_read, temp);
    }
    free(temp);
    return line_read;
}

char *get_next_line(int fd)
{
    //char *line;
    static char *line_read;
    
    if(!fd || !BUFFER_SIZE)
        return NULL;
    line_read = read_line(fd,line_read);
    if(!line_read)
        return NULL;
    
    return line_read;
}

#include <stdio.h>
#include <unistd.h>
int main()
{
    char *buffer;
    int fd = open("test.txt", O_RDONLY);
    //char buff[100];
    buffer = get_next_line(fd);
    printf("%s",buffer);
}
