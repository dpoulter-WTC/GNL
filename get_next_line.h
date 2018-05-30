/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:13:43 by dpoulter          #+#    #+#             */
/*   Updated: 2018/05/29 11:53:09 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

int						get_next_line(const int fd, char **line);

# define BUFF_SIZE 32

typedef unsigned int	t_fpos;

typedef struct			s_file
{
	int		fd;
	char	*buf;
	size_t	bufsize;
	t_fpos	fpos;
	int		flag;
}						t_file;

#endif
