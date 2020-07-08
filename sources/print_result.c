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

int		print_ant(t_in *in, t_ant *ants)
{
	int		i;
	int		turn;

	turn = -1;
	while (ants[in->ant_size - 1].path && (++turn || 1))
	{
		i = -1;
		while (++i < in->ant_size)
		{
			if (ants[i].turn <= turn && ants[i].path &&
				ft_printf("L%i-%s ", i, ants[i].path->name))
				ants[i].path = ants[i].path->next;
		}
		ft_printf("\n");
	}
	ft_printf("NBR LINE : %i\n", ++turn);
	return (1);
}

int		init_ant(t_in *in)
{
	t_ant	*ants;
	int		i;
	int		ant;

	ants = malloc(sizeof(t_ant) * in->ant_size);
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
	print_ant(in, ants);
	return (1);
}

int		add_room(t_in *in, int room_to, t_queue *q, t_queue *end_visit)
{
	t_room		*tmp;
	int			len;
	int			i;
	
	if ((end_visit->next = malloc(sizeof(t_queue))) == NULL)
		return (0);
	end_visit->next->in = room_to;
	end_visit->next->score = q->score + 1;
	end_visit->next->next = NULL;
	i = -1;
	while (in->path[++i]->id != q->in)
		;
	tmp = in->room;
	while (tmp->id != room_to)
		tmp = tmp->next;
	in->path[i]->next = li_lstcpy(tmp);
	in->path[i]->next->score = in->path[i]->score + 1;
	in->path[i]->next->previous = in->path[i];
	in->path[i] = in->path[i]->next;
	if (in->path[i]->id == in->room_count - 1 && (len = in->path[i]->score))
	{
		while (in->path[i]->previous != NULL)
			in->path[i] = in->path[i]->previous;
		in->path[i]->score = len;
	}
	return (1);
}
int		simple_bfs(t_in *in)
{
	t_queue     *q;
	t_queue     *end_visit;
	int			j;

	if ((in->path = malloc(sizeof(t_room*) * in->max_paths)) == NULL)
		return (0);
	if ((q = malloc(sizeof(t_queue))) == NULL)
		return (0);
	q->in = 0;
	q->score = 0;
	q->next = NULL;
	j = -1;
	while (++j < in->max_paths)
		in->path[j] = li_lstcpy(in->room);
	end_visit = q;
	while (q && (j = -1))
	{
		while (++j < in->room_count)
		{
			if (in->matrix[q->in][j] == 1 && in->matrix[j][q->in] == 1 &&
				!(in->matrix[q->in][j] = 0))
				in->matrix[j][q->in] = 0;
			else if (in->matrix[q->in][j] == 1 && add_room(in, j, q, end_visit))
				end_visit = end_visit->next;
		}
		q = q->next;
	}
	return (1);
}
