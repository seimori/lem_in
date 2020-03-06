/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:25:36 by seimori           #+#    #+#             */
/*   Updated: 2020/03/06 04:07:36 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *remove_from_queue(t_room *queue, t_room *node)
{
    t_room      *first;

    first = queue;
    while (queue->next != node)
        queue = queue->next;
    queue->next = queue->next->next;
    return (first);
}

t_room          *reorder_queue(t_room *queue, t_room *neighbor)
{
    t_room      *first;
    t_room      *temp;

    queue = remove_from_queue(queue, neighbor);
    first = queue;
	while (queue->next
    && queue->next->score <= neighbor->score)
    {
        if (queue->next == neighbor)
            return (first);
        queue = queue->next;
    }
	temp = queue->next;
	queue->next = neighbor;
	neighbor->next = temp;
    return(first);
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

t_room          *pathfinder(t_in *in)
{
    t_room      *queue;

    queue = in->room;
    while (queue)
    {
        if (queue == in->end_room)
            return (queue);
		queue = explore_node(in, queue);
        queue = queue->next;
	}
    return (NULL);
}