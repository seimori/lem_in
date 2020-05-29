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
	while (i <= nb_room)
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
	free(mat);
	mat = NULL;
	return (1);
}

int		free_tab(t_names **tab, int nb_room)
{
	int		i;

	i = 0;
	while (i <= nb_room)
	{
		free(tab[i]->name);
		tab[i]->name = NULL;
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (1);
}

int		free_list(t_memlist *mem)
{
	t_memlist	*f;

	while (mem)
	{
		f = mem;
		mem = mem->n;
		if (f->names)
		{
			if (f->names->name)
            	free(f->names->name);
			free(f->names);
			f->names = NULL;
		}
		free(f);
		f = NULL;
	}
	return (1);
}

int		li_free(t_env **e, char **inst, t_memlist *first, int err)
{
	if (err)
		write(2, "Error\n", 6);
	if (e && *e)
	{
		if ((*e)->names)
			free_tab((*e)->names, (*e)->nb_room);
		if ((*e)->links)
			free_mat((*e)->links, (*e)->nb_room);
		free(*e);
		*e = NULL;
	}
	free_list(first);
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
