/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:25:36 by seimori           #+#    #+#             */
/*   Updated: 2020/06/27 17:48:06 by seimori          ###   ########.fr       */
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

t_room          *update_score(t_room *node, t_room *neighbor)
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

t_room          *explore_node(t_in *in, t_room *node)
{
    t_room      *neighbor;

    neighbor = node;
    while (neighbor)
    {
		neighbor = get_next_neighbor(in, node, neighbor);
        if (neighbor)
        {
			neighbor = update_score(node, neighbor);
            node = reorder_queue(node, neighbor);
		}
	}
    return (node);
}

t_room			*copy_room_node(t_room *source)
{
	t_room		*copy;

	copy = (t_room*)ft_memalloc(sizeof(t_room));
	copy->id = source->id;
	copy->x = source->x;
	copy->y = source->y;
	copy->name = source->name;
	copy->score = source->score;
	copy->next = source->next;
	copy->previous = copy->previous;
	copy->trail = source->trail;
	copy->route = source->route;
	copy->ants = source->ants;
	return (copy);
}

t_room          *dijkstra(t_in *in)
{
    t_room      *queue;

    queue = in->room;
    while (queue)
    {
        if (queue == in->end_room)
		{
			queue = copy_room_node(queue);
            return (queue);
		}
		queue = explore_node(in, queue);
        queue = queue->next;
	}
    return (NULL);
}