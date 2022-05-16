/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/16 14:40:24 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				ret;
	char			*line;
	static char		buf[BUFFER_SIZE + 1] = '\0';

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = NULL;
	fill_line(&line, buf);
	while (ret && !ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		buf[ret] = '\0';
		if (ret)
			fill_line(&line, buf);
	}
	if (ret)
		return (clean_line(&line, buf));
	else
		return (NULL);
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
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
    return (0);
}
