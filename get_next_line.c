/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/14 17:57:49 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int			ret;
	char		*line;
	char		*nl;
	char 		*tmp;
	char	buf[BUFFER_SIZE + 1];
	static char *lastline;
	
	printf("START: GET_NEXT_LINE with buf: %s\n", buf);
	if (fd == -1)
        return (NULL);        
	
	printf("READ: GET_NEXT_LINE with buf: %s\n", buf);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line = '\0';
	
	ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
        return (NULL);
	buf[ret] = '\0';
	nl = ft_strchr(buf, '\n');
	while (ret > 0 && !nl)
	{
		printf("Did not find newline but read %d bytes\n", ret);
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		nl = ft_strchr(buf, '\n');
	}
	line = ft_strjoin(line, ft_strndup(buf, (nl - buf) + 1));
	printf("line: %s\n", line);
	printf("buf: %s\n", buf);
	lastline = ft_strndup(line, ft_strlen(line));
	return (line);
}

int main()
{
    int fd;
    
	fd = open("file", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
    return (0);
}