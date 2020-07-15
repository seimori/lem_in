/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/15 16:25:17 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		free_mat(int **mat, int nb_room)
{
	int		i;

	i = 0;
	while (i < nb_room)
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
	free(mat);
	mat = NULL;
	return (1);
}

int		free_room_list(t_room *mem, int room)
{
	t_room	*f;

	while (mem)
	{
		f = mem;
		mem = mem->next;
		if (room && f->name)
			free(f->name);
		f->name = NULL;
		free(f);
		f = NULL;
	}
	return (1);
}

int		free_inst(char **inst)
{
	if (*inst)
	{
		free(*inst);
		*inst = NULL;
	}
	free(inst);
	return (1);
}

int		li_free(t_in **e, char **inst, int err)
{
	int		i;

	if (err)
		write(2, "Error\n", 6);
	if (e && *e)
	{
		if ((*e)->room)
			free_room_list((*e)->room, 1);
		if ((*e)->matrix)
			free_mat((*e)->matrix, (*e)->room_count);
		if ((*e)->oriented)
			free_mat((*e)->oriented, ((*e)->room_count - 1) * 2);
		if ((*e)->path && (i = -1))
		{
			while (++i < (*e)->max_paths)
				free_room_list((*e)->path[i], 0);
			free((*e)->path);
		}
		if ((*e)->map_buf)
			free((*e)->map_buf);
		free(*e);
		*e = NULL;
	}
	if (inst && free_inst(inst))
		inst = NULL;
	ari_get_next_line(-1, NULL);
	return (err);
}
