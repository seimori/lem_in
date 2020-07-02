/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:52:01 by seimori           #+#    #+#             */
/*   Updated: 2020/07/02 08:03:28 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room *update_score_bellman_ford		(t_in *in, t_room *node,
								  		t_room *neighbor)
{
	int			tentative_score;
	int			edge_weight;

	edge_weight = 1;
	tentative_score = node->score + edge_weight;
	if (tentative_score < neighbor->score && tentative_score > 0)
	{
		neighbor->score = tentative_score;
		neighbor->trail = node;
		in->score_change++;
	}
	return (neighbor);
}

t_in			*explore_node_bellman_ford(t_in *in, t_room *node)
{
	t_room		*neighbor;

	neighbor = node;
	while (neighbor)
	{
		neighbor = get_next_neighbor(in, node, neighbor);
		if (neighbor)
		{
			neighbor = update_score_bellman_ford(in, node, neighbor);
		}
	}
	return (in);
}

t_room			*bellman_ford(t_in *in)
{
	t_room		*scan;
	// size_t		room_count; // TODO Convert things to size_t
	int			maximum_cycles;

	scan = in->room;
	maximum_cycles = in->room_count;
	while (maximum_cycles > 0 && in->score_change > 0)
	{
		in->score_change = 0;
		while (scan->next != NULL)
		{
			in = explore_node_bellman_ford(in, scan);
			scan = scan->next;
		}
		scan = in->room;
		maximum_cycles--;
	}
	return (in->end_room);
}