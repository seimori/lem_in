/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/27 03:31:56 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	order_path(t_in *in)
{
	int		order;
	int		i;
	t_room	*tmp;

	order = 1;
	while (order)
	{
		order = 0;
		i = -1;
		while (++i < in->max_paths - 1)
		{
			if (in->path[i]->score > in->path[i + 1]->score)
			{
				tmp = in->path[i];
				in->path[i] = in->path[i + 1];
				in->path[i + 1] = tmp;
				order = 1;
			}
		}
	}
}

int		print_ant(t_in *in)
{
	int		i;
	int		turn;

	turn = -1;
	while (in->ants[in->ant_size - 1].path && (++turn || 1))
	{
		i = -1;
		while (++i < in->ant_size)
		{
			if (in->ants[i].turn <= turn && in->ants[i].path &&
				ft_printf("L%i-%s ", i, in->ants[i].path->name))
				in->ants[i].path = in->ants[i].path->next;
		}
		ft_printf("\n");
	}
	ft_printf("NBR LINE : %i\n", turn + 1);
	return (1);
}

void		init_ant(t_in *in, t_ant *ants)
{
	int		i;
	int		ant;

	ant = -1;
	while (++ant < in->ant_size)
	{
		i = (in->path[0]->score == 1 ? 0 : in->max_paths - 1);
		while (i && in->path[i]->score + in->path[i]->ants >=
							in->path[i - 1]->score + in->path[i - 1]->ants)
			i--;
		ants[ant].turn = (in->path[0]->score == 1 ? 0 : in->path[i]->ants);
		ants[ant].path = in->path[i]->next;
		in->path[i]->ants++;
	}
	if (in->ants == NULL && (in->best = in->path) && (in->max_best = in->max_paths))
		in->ants = ants;
	else if (ants[ant - 1].turn + ants[ant - 1].path->previous->score <
			in->ants[ant - 1].turn + in->ants[ant - 1].path->previous->score)
	{
		free_room_list(in->best, in->max_best, 0);
		in->best = in->path;
		in->max_best = in->max_paths;
		free(in->ants);
		in->ants = ants;
	}
	else
	{
		free_room_list(in->path, in->max_paths, 0);
		free(ants);
	}
}

t_queue	*add_room(t_in *in, int room_to, t_queue *q, t_queue *end_visit)
{
	t_room		*tmp;
	int			len;
	int			i;
	
	if ((end_visit->next = add_queue(room_to, q->score + 1, NULL)) == NULL)
		return (free_queue(q));
	i = -1;
	while (in->path[++i]->id != q->in)
		;
	tmp = in->room;
	while (tmp->id != room_to)
		tmp = tmp->next;
	if ((in->path[i]->next = li_lstcpy(tmp)) == NULL)
		return (free_queue(q));
	in->path[i]->next->score = in->path[i]->score + 1;
	in->path[i]->next->previous = in->path[i];
	in->path[i] = in->path[i]->next;
	if (in->path[i]->id == in->room_count - 1 && (len = in->path[i]->score))
	{
		while (in->path[i]->previous != NULL)
			in->path[i] = in->path[i]->previous;
		in->path[i]->score = len;
	}
	return (end_visit->next);
}
int		simple_bfs(t_in *in)
{
	t_queue     *q;
	t_queue     *endq;
	t_queue     *tmp;
	int			j;

	if (!(in->path = malloc(sizeof(t_room*) * in->max_paths)) ||
	!(j = -1) || !(q = add_queue(0, 0, NULL)))
		return (0);
	while (++j < in->max_paths)
		if (!(in->path[j] = li_lstcpy(in->room)) && !free_queue(q))
			return (0);
	endq = q;
	while (q && (j = -1))
	{
		while (++j < in->room_count)
			if (in->matrix[q->in][j] == 1 && !(endq = add_room(in, j, q, endq)))
				return (0);
		tmp = q;
		q = q->next;
		free(tmp);
	}
	return (1);
}
