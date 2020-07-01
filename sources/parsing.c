/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/21 16:07:26 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_map(int fd, char **inst)
{
	if (*inst)
	{
		free(*inst);
		*inst = NULL;
	}
	while (ari_get_next_line(fd, inst) == 1 && *inst != NULL)
	{
		ft_printf("%s", *inst);
		free(*inst);
		*inst = NULL;
	}
}

void	print_links(t_in *e)
{
	int		i;
	int		j;
	t_room	*current;

	i = -1;
	ft_printf("\n                  ");
	while (++i < e->room_count)
		ft_printf("[%3i]", i);
	ft_printf("\n");
	i = -1;
	current = e->room;
	while (++i < e->room_count)
	{
		ft_printf("%10.10s [%3i]:", current->name, i);
		j = -1;
		while (++j < e->room_count)
			ft_printf("  %3i", e->matrix[i][j]);
		if (i == 0)
			ft_printf("  START");
		else if (e->end_room->id == i)
			ft_printf("  END");
		ft_printf("\n");
		current = current->next;
	}
}

int		add_to_buf(char **inst, char **buf)
{
	int		i;
	int		size_buf;
	char	*new_buf;

	if (((size_buf = ft_strlen(*buf)) + ft_strlen(*inst)) >= BUFF_SIZE)
	{
		if (!(new_buf = ft_memalloc(size_buf + BUFF_SIZE)))
			return (0);
		ft_memcpy(new_buf, *buf, size_buf);
		free(*buf);
		*buf = new_buf;
	}
	i = 0;
	while ((*inst)[i])
	{
		(*buf)[size_buf + i] = (*inst)[i];
		i++;
	}
	(*buf)[size_buf + i] = 0;
	free(*inst);
	*inst = NULL;
	return (1);
}

int		read_map(t_in *e, char **inst)
{
	t_room	*mem;

	mem = e->room;
	while (ari_get_next_line(e->fd, inst) == 1 && *inst != NULL)
	{
		if (*inst[0] == '#' &&
		ft_strcmp(*inst, "##start\n") && ft_strcmp(*inst, "##end\n"))
			;
		else if (e->ant_size == -1)
		{
			if (li_atoi(*inst, &e->ant_size, '\n') == 0 || e->ant_size <= 0)
				break ;
		}
		else if (!e->matrix && !ft_strstopchr(*inst, '-', ' '))
		{
			if (!fill_names(e, inst, &mem))
				break ;
		}
		else if (ft_strchr(*inst, '-'))
		{
			if (!fill_links(e, inst, mem))
				break ;
		}
		else
			break ;
		add_to_buf(inst, &e->map_buf);
	}
	return (e->matrix ? 1 : 0);
}

t_in	*parsing(char *pathname)
{
	t_in		*e;
	char		**inst;

	//e = NULL;
	//inst = NULL;
	if (!(e = malloc(sizeof(t_in))) ||
	!(inst = malloc(sizeof(char*))) ||
	!(e->room = li_lstnew()) ||
	!(e->map_buf = ft_memalloc(BUFF_SIZE)))
		return (0);
	e->ant_size = -1;
	e->end_room = NULL;
	e->room_count = 0;
	e->matrix = NULL;
	e->max_paths = 0;
	e->fd = (pathname) ? open(pathname, FLAGS) : STDIN_FILENO;
	if (read_map(e, inst) == 0)
		li_free(&e, inst, 1);
	else
		li_free(NULL, inst, 0);
	return (e);
}
