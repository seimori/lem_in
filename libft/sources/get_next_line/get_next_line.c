/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:10:29 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/27 17:24:33 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../includes/libft.h"

/*
**	concatenate buf->line
**	if buf's size >= *line's size
**	  Reallocate *line to buf's size
*/

void		ft_cat_line(char **line, unsigned int *count, char *buf)
{
	char	*tmp;

	*count += BUFF_SIZE;
	if (*count >= LINE_SIZE)
	{
		tmp = *line;
		*line = ft_memalloc(*count + 1);
		ft_strcpy(*line, tmp);
		free(tmp);
	}
	ft_strcat(*line, buf);
}

/*
**	Returns 1 if source contains '\n'
**	  Add to line : source until '\n'
**	  Copy to newline : source after '\n'
**	Returns 0 if source contains no '\n'
*/

int			ft_has_new_line(char *line, char *source, char *buffer)
{
	char	*tmp;
	size_t	len;

	if ((tmp = ft_strchr(source, '\n')))
	{
		len = tmp - source;
		ft_strncat(line, source, len);
		ft_strncpy(buffer, &source[len + 1], BUFF_SIZE - len);
		return (1);
	}
	return (0);
}

/*
**	Read from fd
**	while(ret != 0)
**	  if no '\n' : concatenate buf->line
**	  else : return 1 (print line)
**	EOF
**	  if buffer has '\n' : return 1 (print line)
**	  else : reset buffer
**	    (to avoid ft_strcpy(*line, buffer->str))
**	  if *line is not empty : return 1 (print line)
**	    (if there is no line feed)
*/

int			ft_fill_line(char **line, t_buffer *buffer)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	unsigned int	count;

	count = 0;
	while ((ret = read(buffer->fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if ((ft_has_new_line(*line, buf, buffer->str)))
			return (1);
		else
			ft_cat_line(line, &count, buf);
	}
	if ((ft_has_new_line(*line, buffer->str, buffer->str)))
		return (1);
	else
		ft_bzero(buffer->str, BUFF_SIZE + 1);
	if (ft_strcmp(*line, ""))
		return (1);
	return (0);
}

/*
**	Initialize head (if !head)
**	Check for fd in head then next (current->next)
**	Create current->next if no fd match
*/

t_buffer	*set_buffer(int fd, t_buffer **head)
{
	t_buffer	*current;

	if (!(*head))
	{
		*head = (t_buffer*)ft_memalloc(sizeof(t_buffer));
		(*head)->fd = fd;
		(*head)->str = ft_memalloc(BUFF_SIZE + 1);
		(*head)->str[0] = '\0';
		(*head)->next = NULL;
	}
	if ((*head)->fd == fd)
		return (*head);
	current = *head;
	while (current->next)
	{
		if (current->next->fd == fd)
			return (current->next);
		current = current->next;
	}
	current->next = (t_buffer*)ft_memalloc(sizeof(t_buffer));
	current->next->fd = fd;
	current->next->str = ft_memalloc(BUFF_SIZE + 1);
	current->next->str[0] = '\0';
	current->next->next = NULL;
	return (current->next);
}

/*
**	Master function for get_buffer
**	  Error check + set buffer
**	  Allocate *line
**	  Check for '\n' in buffer
**	  Copy buffer string in *line
**	  Return ft_fill_line (1 for print, 0 for end, -1 for error)
*/

int			get_next_line(const int fd, char **line)
{
	static t_buffer		*buffer_head = NULL;
	t_buffer			*buffer;
	int					ret;

	if (!line || fd < 0 || BUFF_SIZE < 1 ||
			!(buffer = set_buffer(fd, &buffer_head)))
		return (-1);
	*line = ft_memalloc(LINE_SIZE + 1);
	if ((ft_has_new_line(*line, buffer->str, buffer->str)))
		return (1);
	else
		ft_strcpy(*line, buffer->str);
	ret = ft_fill_line(line, buffer);
	if (ret > 0)
		return (ret);
	while (buffer_head->next)
	{
		buffer = buffer_head;
		buffer_head = buffer_head->next;
		free(buffer->str);
		free(buffer);
	}
	free(buffer_head->str);
	free(buffer_head);
	return (ret);
}
