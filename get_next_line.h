/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omozo-av <omozo-av@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:28:24 by omozo-av          #+#    #+#             */
/*   Updated: 2022/12/04 00:40:12 by omozo-av         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#if (BUFFER_SIZE < 0)
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>


char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char     *get_next_line(int fd);
size_t		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char *get_next_line(int fd);
char *read_line(int fd, char *line_read);

#endif
// Norminette: -R CheckDefine 