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

int		free_list(t_room *mem)
{
	t_room	*f;

	while (mem)
	{
		f = mem;
		mem = mem->next;
		if (f->name)
			free(f->name);
		f->name = NULL;
		free(f);
		f = NULL;
	}
	return (1);
}

int		li_free(t_in **e, char **inst, int err)
{
	if (err)
		write(2, "Error\n", 6);
	if (e && *e)
	{
		if ((*e)->room)
			free_list((*e)->room);
		if ((*e)->matrix)
			free_mat((*e)->matrix, (*e)->room_count);
		if ((*e)->map_buf)
			free((*e)->map_buf);
		free(*e);
		*e = NULL;
	}
	if (inst)
	{
		if (*inst)
		{
			free(*inst);
			*inst = NULL;
		}
		free(inst);
		inst = NULL;
	}
	ari_get_next_line(-1, NULL);
	return (err);
}
