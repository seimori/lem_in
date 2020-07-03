/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:25:36 by seimori           #+#    #+#             */
/*   Updated: 2020/07/03 05:09:16 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *remove_from_queue(t_room *node)
{
	if (node->previous && node->next)
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
	}
	else if (node->next)
		node->next->previous = NULL;
	else if (node->previous)
		node->previous->next = NULL;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

t_room			*insert_neighbor(t_room *scan, t_room *neighbor)
{
	if (scan->previous)
	{
		scan->previous->next = neighbor;
		neighbor->previous = scan->previous;
	}
	else
		neighbor->previous = NULL;
	neighbor->next = scan;
	scan->previous = neighbor;
	return (neighbor);
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
	if (scan != neighbor)
	{
		neighbor = remove_from_queue(neighbor);
		neighbor = insert_neighbor(scan, neighbor);
	}
	return (queue);
}

t_room          *update_score_dijkstra(t_room *node, t_room *neighbor)
{
	int tentative_score;

	tentative_score = node->score + 1;
	if (tentative_score < neighbor->score && tentative_score > 0)
	{
		neighbor->score = tentative_score;
		neighbor->trail = node;
	}
	return (neighbor);
}

t_room          *explore_node_dijkstra(t_in *in, t_room *node)
{
    t_room      *neighbor;
	int			stop;

    neighbor = node;
    while (neighbor)
    {
		neighbor = get_next_neighbor(in, node, neighbor);
        if (neighbor)
        {
			neighbor = update_score_dijkstra(node, neighbor);
            node = reorder_queue(node, neighbor);
			if (neighbor->score >= INF)
				stop = 1;
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
        if (queue == in->end_room && queue->score < INF)
		{
			// queue = copy_room_node(queue);
			*path = copy_room_node(queue, *path);
            return (path);
		}
		queue = explore_node_dijkstra(in, queue);
        queue = queue->next;
	}
    return (NULL);
}