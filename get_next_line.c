/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:23:07 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/29 11:56:05 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	int		nread;
	char 	*test;

	if(!(test = ft_strnew((size_t)BUFF_SIZE)))
		return (0);
	nread=read(fd,test,BUFF_SIZE);
	if(nread == 0)
		return (0);
	printf("%s\n", test);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	get_next_line(fd, &str);
	return 0;
}  
