/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/21 16:07:26 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_name(t_env *e, char *name)
{
	int		i;

	i = 0;
	while (i <= e->nb_room)
	{
		if (ft_strcmp(e->names[i]->name, name) == 0)
			return (e->names[i]->id);
		i++;
	}
	return (-1);
}

int		init_links(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->links = malloc(sizeof(int*) * (e->nb_room + 1))))
		return (0);
	while (++i <= e->nb_room)
		if (!(e->links[i] = malloc(sizeof(int*) * (e->nb_room + 1))))
			return (0);
	i = -1;
	while (++i <= e->nb_room)
	{
		j = -1;
		while (++j <= e->nb_room)
			e->links[i][j] = 0;
	}
	return (1);
}

int		fill_links(t_env *e, char **inst, t_memlist *f, t_memlist *mem)
{
	char	*dash;
	int		id_room1;
	int		id_room2;

	if (e->names == NULL && !list_to_tab(e, f, mem->names->id))
		return (0);
	if (e->links == NULL && !init_links(e))
		return (0);
	if (*inst == NULL || !(dash = ft_strchr(*inst, '-')))
		return (0);
	*dash = '\0';
	if (ft_strchr(dash + 1, '\n'))
		*ft_strchr(dash + 1, '\n') = '\0';
	if ((id_room1 = check_name(e, *inst)) == -1 ||
	(id_room2 = check_name(e, dash + 1)) == -1)
		return (0);
	e->links[id_room1][id_room2] = (id_room1 == id_room2 ? 0 : 1);
	e->links[id_room2][id_room1] = (id_room1 == id_room2 ? 0 : 1);
	return (1);
}

int		check_duplicate(t_memlist *m, t_memlist *f)
{
	while (f != m->n)
	{
		if (ft_strcmp(f->names->name, m->n->names->name) == 0 ||
		(m->n->names->startend > 0 &&
		f->names->startend == m->n->names->startend) ||
		(f->names->x == m->n->names->x && f->names->y == m->n->names->y))
			return (0);
		f = f->n;
	}
	return (1);
}

int		fill_names(char **inst, t_memlist **mem, t_memlist *first)
{
	char		*coords;

	if ((*mem)->n == NULL && ((*mem)->n = li_lstnew()) == NULL)
		return (0);
	if ((*mem)->n->names->startend == 0 &&
        ((!(ft_strcmp(*inst, "##end\n")) && ((*mem)->n->names->startend = 2)) ||
		(!(ft_strcmp(*inst, "##start\n")) && ((*mem)->n->names->startend = 1))))
		return (1);
	if (*inst == NULL || **inst == 'L' || ft_strchr(*inst, ' ') == NULL ||
	((*mem)->n->names->name = ft_strcut(*inst, ' ', 0)) == NULL)
		return (0);
	//free coords
	coords = ft_strcut(*inst, ' ', 1);
	if (li_atoi(li_atoi(coords, &(*mem)->n->names->x, ' ') + 1,
	&(*mem)->n->names->y, '\n') == NULL || !check_duplicate(*mem, first->n))
		return (0);
	(*mem)->n->names->id = (*mem)->names->id + 1;
	*mem = (*mem)->n;
	return (1);
}