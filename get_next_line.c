/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/13 17:52:59 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int			ret;
	char		*line;
	char		*nl;
	char 		*tmp;
	static char	buf[BUFFER_SIZE + 1];
	
	if (fd == -1)
        return (NULL);              
	ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
        return (NULL);
	buf[ret] = '\0';
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line = '\0';
	nl = ft_strchr(buf, '\n');
	while (ret > 0 && !nl)
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		nl = ft_strchr(buf, '\n');
	}
	line = ft_strjoin(line, ft_strndup(buf, nl - buf));
	return (line);
}

int main()
{
    int fd;
    
	fd = open("file", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
    return (0);
}