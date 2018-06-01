/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:15 by dpoulter          #+#    #+#             */
/*   Updated: 2018/06/01 15:03:49 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		buff[1000][BUFF_SIZE + 1];
	int				i;
	int				j;
	int				buff_count;

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	if (!(*line = (char *)malloc(52000)))
		return (-1);
	buff_count = ft_strlen(&buff[fd][0]);
	if (buff_count == 0)
		buff_count = read(fd, &buff[fd][0], BUFF_SIZE);
	buff[fd][buff_count + 1] = 0;
	i = -1;
	while (buff_count > 0)
	{
		j = 0;
		while (j < buff_count)
		{
			(*line)[++i] = buff[fd][j++];
			if ((*line)[i] == '\n' && ((*line)[i] = 0) == 0)
			{
				ft_strcpy(&buff[fd][0], &buff[fd][j]);
				return (1);
			}
		}
		buff_count = read(fd, &buff[fd][0], BUFF_SIZE);
		buff[fd][buff_count] = 0;
	}
	if (i >= 0)
		return (1);
	return (buff_count);
}
