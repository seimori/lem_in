/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/06/19 18:29:33 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_name(t_in *e, char *name)
{
	t_room	*current;

	current = e->room;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current->id);
		current = current->next;
	}
	return (-1);
}

int		init_links(t_in *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->matrix = malloc(sizeof(int*) * (e->room_count))))
		return (0);
	while (++i < e->room_count)
		if (!(e->matrix[i] = malloc(sizeof(int*) * (e->room_count))))
			return (0);
	i = -1;
	while (++i < e->room_count)
	{
		j = -1;
		while (++j < e->room_count)
			e->matrix[i][j] = 0;
	}
	return (1);
}

int		fill_links(t_in *e, char **inst, t_room *mem)
{
	char	*dash;
	int		id_room1;
	int		id_room2;

	if (e->room_count == 0 && !clean_room_list(e, mem))
		return (0);
	if (e->matrix == NULL && !init_links(e))
		return (0);
	if (*inst == NULL || !(dash = ft_strchr(*inst, '-')))
		return (0);
	*dash = '\0';
	if (ft_strchr(dash + 1, '\n'))
		*ft_strchr(dash + 1, '\n') = '\0';
	if ((id_room1 = check_name(e, *inst)) == -1 ||
	(id_room2 = check_name(e, dash + 1)) == -1)
		return (0);
	e->matrix[id_room1][id_room2] = (id_room1 == id_room2 ? 0 : 1);
	e->matrix[id_room2][id_room1] = (id_room1 == id_room2 ? 0 : 1);
	*dash = '-';
	(*inst)[ft_strlen(*inst)] = '\n';
	return (1);
}

int		check_duplicate(t_room *m, t_room *f)
{
	while (f != m->next)
	{
		if (ft_strcmp(f->name, m->next->name) == 0 ||
		(m->next->score == 0 && f->score == 0) ||
		(f->x == m->next->x && f->y == m->next->y))
			return (0);
		f = f->next;
	}
	return (1);
}

int		fill_names(t_in *e, char **inst, t_room **mem)
{
	if ((*mem)->next == NULL && ((*mem)->next = li_lstnew()) == NULL)
		return (0);
	if ((e->end_room == NULL && (*mem)->next != e->start_room &&
		!(ft_strcmp(*inst, "##end\n")) && (e->end_room = (*mem)->next)) ||
		(e->start_room == NULL && (*mem)->next != e->end_room &&
		!(ft_strcmp(*inst, "##start\n")) && (e->start_room = (*mem)->next)))
		return (1);
	if (*inst == NULL || **inst == 'L' || ft_strchr(*inst, ' ') == NULL ||
	((*mem)->next->name = get_name(*inst)) == NULL)
		return (0);
	if (li_atoi(li_atoi(ft_strchr(*inst, ' ') + 1, &(*mem)->next->x, ' ') + 1,
	&(*mem)->next->y, '\n') == NULL || !check_duplicate(*mem, e->room->next))
		return (0);
	(*mem)->next->id = (*mem)->id +
		((*mem)->next == e->end_room || (*mem)->next == e->start_room ? 0 : 1);
	(*mem)->next->id += ((*mem)->id == -1 ? 1 : 0);
	*mem = (*mem)->next;
	return (1);
}

/*int		fill_names(t_in *e, char **inst, t_room **mem)
{
	char		*coords;

	if ((*mem)->next == NULL && ((*mem)->next = li_lstnew()) == NULL)
		return (0);
	(*mem)->next->previous = (*mem);
	if (((e->end_room == NULL && (*mem)->next->score != 0 &&
		!(ft_strcmp(*inst, "##end\n")) && (e->end_room = (*mem)->next)) ||
		((*mem)->next->score != 0 && (*mem)->next != e->end_room &&
		!(ft_strcmp(*inst, "##start\n")) && !((*mem)->next->score = 0))))
		return (1);
	if (*inst == NULL || **inst == 'L' || ft_strchr(*inst, ' ') == NULL ||
	((*mem)->next->name = get_name(*inst)) == NULL)
		return (0);
	coords = ft_strchr(*inst, ' ') + 1;
	if (li_atoi(li_atoi(coords, &(*mem)->next->x, ' ') + 1,
	&(*mem)->next->y, '\n') == NULL || !check_duplicate(*mem, e->room->next))
		return (0);
	(*mem)->next->id = (*mem)->id + ((*mem)->next == e->end_room ||
									(*mem)->next->score == 0 ? 0 : 1);
	(*mem)->next->id += ((*mem)->id == -1 ? 1 : 0);
	*mem = (*mem)->next;
	return (1);
}*/
