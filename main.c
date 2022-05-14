/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:39:57 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/14 16:42:58 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char *str;
	char *ptr;
	int	i;

	str = "salam";
	ptr = str;
	i = 0;
	while (i < 3)
	{
		ptr++;
		i++;
	}
	printf("str: %s\nptr: %s\nptr - str: %ld\n", str, ptr, ptr - str);
	return (0);
}