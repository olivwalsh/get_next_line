/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/17 16:43:12 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				ret;
	char			*line;

	if ((fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = NULL;
	line = ft_strjoin(line, buf[fd]);
	while (ret && !has_nl(line))
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		if (ret)
		{
			buf[fd][ret] = '\0';
			line = ft_strjoin(line, buf[fd]);
		}
	}
	clean_buf(buf[fd]);
	return (line);
}

// int    main(void)
// {
//     int    fd1;
//     int    fd2;
//     int    fd3;
//     char    *result1 = NULL;
//     char    *result2 = NULL;
//     char    *result3 = NULL;
//     int    i;

//     i = 0;
//     fd1 = open("check/check1", O_RDONLY);
//     fd2 = open("check/check2", O_RDONLY);
//     fd3 = open("check/check3", O_RDONLY);
//     if (fd1 == -1 || fd2 == -1 || fd3 == -1)
//         return (0);
//     while (i < 5)
//     {
//         result1 = get_next_line(fd1);
//         printf("%s%ld\n", result1, ft_strlen(result1));
//         free (result1);
//         result2 = get_next_line(fd2);
//         printf("%s%ld\n", result2, ft_strlen(result2));
//         free (result2);
//         result3 = get_next_line(fd3);
//         printf("%s%ld\n", result3, ft_strlen(result3));
//         free (result3);
//         i++;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }