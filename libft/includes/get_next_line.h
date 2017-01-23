/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:19:28 by rle               #+#    #+#             */
/*   Updated: 2016/12/26 14:12:30 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft.h>

typedef struct			s_file
{
	int					file;
	int					ret;
	char				*extra;
	struct s_file		*next;
}						t_file;

int						get_next_line(const int fd, char **line);

#endif
