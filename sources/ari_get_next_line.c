/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ari_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:01 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/27 05:04:59 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ari_get_next_line.h"

t_fd	*fd_choice(int fd, t_fd *file)
{
	t_fd	*begin;

	begin = file;
	while ((size_t)fd != file->fd)
	{
		file = file->next;
		if (file == begin)
		{
			if (!(file = malloc(sizeof(t_fd))) ||
				!(file->buf = ft_strnew(BUFF_SIZE)))
				return (NULL);
			file->fd = (size_t)fd;
			file->red = 0;
			file->next = begin->next;
			begin->next = file;
		}
	}
	return (file);
}

int		readline(int fd, char *buf, int *red, char **copy)
{
	int		i;
	char	end;

	end = 0;
	while (end != '\n')
	{
		if (!*buf && (*red = read(fd, buf, BUFF_SIZE)) == 0)
			return (0);
		buf[*red] = '\0';
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		end = buf[i];
		buf[i] = '\0';
		*copy = ft_strjoinfree(*copy, buf, end, 1);
		if (end == '\n')
			ft_memmove(buf, (buf + i + 1), *red - i);
		end == '\n' ? ft_strclr(buf + *red - i - 1) : ft_strclr(buf);
		if (end != '\n' && (*red = read(fd, buf, BUFF_SIZE)) == 0 &&
						(*copy = ft_strjoinfree(*copy, "\n", 0, 1)))
			return (1);
	}
	return (1);
}

int		free_file(t_fd **file)
{
	t_fd	*to_free;
	t_fd	*begin;

	begin = *file;
	while (*file)
	{
		to_free = *file;
		if (to_free->buf)
		{
			free(to_free->buf);
			to_free->buf = NULL;
		}
		*file = ((*file)->next != begin) ? (*file)->next : NULL;
		free(to_free);
		to_free = NULL;
	}
	return (1);
}

int		ari_get_next_line(const int fd, char **line)
{
	static t_fd		*file;
	char			*copy;
	int				ret;

	if (fd == -1)
		return (free_file(&file));
	if (!file)
	{
		if (!(file = malloc(sizeof(t_fd))) ||
			!(file->buf = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		file->fd = (size_t)fd;
		file->red = 0;
		file->next = file;
	}
	if (fd < 0 || !(copy = ft_strnew(1)) || read(fd, copy, 0) == -1 ||
			BUFF_SIZE < 0 || !line || !(file = fd_choice(fd, file)))
		return (-1);
	ret = readline((int)file->fd, file->buf, &file->red, &copy);
	*line = copy;
	return (ret);
}
