/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:44 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/17 10:42:57 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		has_nl(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	clean_buf(char *buf);

#endif
