/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ari_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:07:48 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/15 17:04:33 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "lem_in.h"

typedef struct		s_fd
{
	void			*buf;
	size_t			fd;
	int				red;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
