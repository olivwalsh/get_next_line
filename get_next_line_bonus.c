/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/17 12:15:28 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		**buf;
	int				ret;
	char			*line;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = NULL;
	line = ft_strjoin(line, *buf[fd]);
	while (ret && !has_nl(line))
	{
		ret = read(fd, *buf[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		if (ret)
		{
			buf[fd][ret] = '\0';
			line = ft_strjoin(line, *buf[fd]);
		}
	}
	clean_buf(*buf[fd]);
	return (line);
}

int main(void)
{
    int		fd;
	int		i;
	char	*line;

	fd = open("file", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		if (i > 2)
			fd = open("test", O_RDONLY);
		line = get_next_line(fd);
		printf("LINE %d:\n%s", i + 1, line);
		free(line);
		i++;
	}
    return (0);
}
