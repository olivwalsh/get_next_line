/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/15 17:32:48 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0 || ret == EOF || !ret)
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
	// printf("Segfaults before strndup?\n");
	line = ft_strndup(stash);
	// printf("Segfaults after strndup?\n");
	while (stash && *stash != '\n' && *stash != 0)
		stash++;
	stash++;
	// printf("Segfaults after moving stash?\n");
	return (line);
}

int main(void)
{
    int		fd;
	int		i;
	char	*line;

	fd = open("file", O_RDONLY | O_CREAT);
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
