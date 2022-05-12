/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:37 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/12 12:53:42 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_file(int fd)
{
    int		ret;
    static char	buf[BUFFER_SIZE];
	int		c;
	char	*line;
	char	*nl;
	int		i;

    if (fd == -1)
        return (NULL);
	line = NULL;
	nl = NULL;
	nl	=	ft_strchr(buf, '\n');
	while (!nl)
	{
		//	join buffer with line
		//	read new buffer
		nl	=	ft_strchr(buf, '\n');
	}
	// extend line with buf until \n (included)
	// move post \n buf data at begining of buf
	// return line.
	

	ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
        return (NULL);
	line = 0;
	while (buf && *buf)
	{
		if (line == get_line)
			break;
		if (*buf != '\n')
		{
			i++;
		}
		else
		{
			buf += i;
			line++;
		}
		buf++;
		
	}
	printf("read %d bytes\n------------\n", ret);
    buf[ret] = '\0';
    return (buf);
}