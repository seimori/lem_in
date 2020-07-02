/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:25:36 by seimori           #+#    #+#             */
/*   Updated: 2020/07/01 16:24:25 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *remove_from_queue(t_room *node)
{
	if (node->previous)
		node->previous->next = node->next;
	if (node->next)
		node->next->previous = node->previous;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

t_room          *reorder_queue(t_room *queue, t_room *neighbor)
{
    t_room      *scan;

    scan = neighbor;
	while (scan->previous
	&& scan->previous->score > neighbor->score)
	{
		scan = scan->previous;
	}
	if (scan != neighbor && scan->previous)
	{
		neighbor = remove_from_queue(neighbor);
		scan->previous->next = neighbor;
		neighbor->previous = scan->previous;
		neighbor->next = scan;
		scan->previous = neighbor;
	}
	return (queue);
}

t_room          *update_score_dijkstra(t_room *node, t_room *neighbor)
{
	int tentative_score;

	tentative_score = node->score + 1;
	if (tentative_score < neighbor->score)
	{
		neighbor->score = tentative_score;
		neighbor->trail = node;
	}
	return (neighbor);
}

t_room          *explore_node_dijkstra(t_in *in, t_room *node)
{
    t_room      *neighbor;

    neighbor = node;
    while (neighbor)
    {
		neighbor = get_next_neighbor(in, node, neighbor);
        if (neighbor)
        {
			neighbor = update_score_dijkstra(node, neighbor);
            node = reorder_queue(node, neighbor);
		}
	}
    return (node);
}

t_room          *dijkstra(t_in *in, t_room *path)
{
    t_room      *queue;

    queue = in->room;
    while (queue)
    {
        if (queue == in->end_room)
		{
			// queue = copy_room_node(queue);
			path = queue;
            return (path);
		}
		queue = explore_node_dijkstra(in, queue);
        queue = queue->next;
	}
    return (NULL);
}