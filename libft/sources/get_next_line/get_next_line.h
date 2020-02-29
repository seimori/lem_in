/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:45:26 by imorimot          #+#    #+#             */
/*   Updated: 2019/01/18 13:41:31 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42
# define LINE_SIZE 4086

typedef struct			s_buffer
{
	int					fd;
	char				*str;
	struct s_buffer		*next;
}						t_buffer;

int						get_next_line(const int fd, char **line);

#endif
