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

t_queue	*free_queue(t_queue *q)
{
	t_queue	*tmp;

	while (q)
	{
		tmp = q;
		q = q->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

void	retrace_path(t_in *in, int room_in)
{
	int		tmp;
	int		prev;

	in->oriented[(in->room_count - 1) * 2 - 1][room_in] = -1;
	in->oriented[room_in][(in->room_count - 1) * 2 - 1] = 0;
	in->matrix[room_in / 2][in->room_count - 1] = 1;
	prev = (in->room_count - 1) * 2 - 1;
	while (room_in)
	{
		tmp = (in->oriented[room_in][0] < 0 ? 0 : in->oriented[room_in][0]);
		in->oriented[room_in][tmp] = -1;
		in->oriented[tmp][room_in] = 0;
		if (tmp + (tmp % 2) != room_in + (room_in % 2))
		{
			in->matrix[(tmp + (tmp % 2)) / 2][(room_in + (room_in % 2)) / 2] = 1;
			if (in->oriented[room_in][prev] == 1)
				in->oriented[room_in][prev] = 0;
			prev = room_in;	
		}
		room_in = (in->oriented[room_in][0] < 0 ? 0 : in->oriented[room_in][0]);
	}
	tmp = 0;
	while (++tmp < (in->room_count - 1) * 2)
		in->oriented[tmp][0] = (in->oriented[tmp][0] == -1 ? -1 : 0);
}

t_queue		*explore_room(t_in *in, t_queue **to_visit, t_queue *tmp)
{
	int			j;
	t_queue		*end_visit;

	j = 0;
	while (++j <= (in->room_count - 2) * 2)
	{
		if ((in->oriented[(*to_visit)->in][j] == 1 ||
			in->oriented[(*to_visit)->in][j] == -1) && in->oriented[j][0] == 0)
		{
			end_visit = *to_visit;
			while (in->oriented[(*to_visit)->in][j] == 1 && end_visit->next != NULL)
				end_visit = end_visit->next;
			tmp = (*to_visit)->next;
			if ((end_visit->next = malloc(sizeof(t_queue))) == NULL)
				return (free_queue(*to_visit));
			end_visit->next->in = j;
			end_visit->next->score = (*to_visit)->score + in->oriented[(*to_visit)->in][j];
			end_visit->next->next = (in->oriented[(*to_visit)->in][j] == -1 ? tmp : NULL);
			in->oriented[j][0] = ((*to_visit)->in == 0 ? -3 : (*to_visit)->in);
		}
	}
	end_visit = (*to_visit)->next;
	free(*to_visit);
	*to_visit = NULL;
	return (end_visit);
}

int		oriented_bfs(t_in *in)
{
	t_queue     *to_visit;

	if ((to_visit = malloc(sizeof(t_queue))) == NULL)
		return (0);
	to_visit->in = 0;
	to_visit->score = 2;
	to_visit->next = NULL;
	while (to_visit)
	{
		if (in->oriented[to_visit->in][(in->room_count - 1) * 2 - 1])
		{
			retrace_path(in, to_visit->in);
			free_queue(to_visit);
			return (1);
		}
		to_visit = explore_room(in, &to_visit, NULL);
	}
	free_queue(to_visit);
	return (0);
}
