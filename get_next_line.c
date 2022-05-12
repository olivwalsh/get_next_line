/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/12 08:45:23 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *line;
    
    line = NULL;
    return (line);
}

void    get_line(void)
{
    
    printf("line: %d\n", line);
    line++;
}

int main()
{
    int i;
    
    read_file("file");
    
    i = 0;
    // while (i < 3)
    // {
    //     get_line();
    //     i++;
    // }

    return (0);
}