/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:37 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/12 08:44:41 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_file(char *file)
{
    int fd;
    int ret;
    char buf[BUFFER_SIZE + 1];

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
        return (NULL);
    buf[ret] = '\0';
    printf("buf:\n%s\n", buf);
    return (buf);
}