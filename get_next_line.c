/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/15 16:42:58 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int			ret;
	char		*line;
	char 		*tmp;
	char	    buf[BUFFER_SIZE + 1];
	static char *stash;
	
	ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
        return (NULL);
	buf[ret] = '\0';
    stash = ft_strjoin(stash, buf);
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
        ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
        free(tmp);
	}
    line = ft_strndup(stash);
    while (*stash != '\n')
        stash++;
    stash++;
    printf("returned line: %s\n", line);
	return (line);
}

int main()
{
    int fd;
    
	fd = open("file", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
    get_next_line(fd);
    return (0);
}