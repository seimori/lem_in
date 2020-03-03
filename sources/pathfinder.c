/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:25:36 by seimori           #+#    #+#             */
/*   Updated: 2020/03/03 17:52:58 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *get_room(t_room *node, int id)
{
    while (node)
    {
        if (node->id == id)
            return(node);
        node = node->next;
    }
    return (NULL);
}

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

int             **update_matrix(t_in *in, int col, int row)
{
    in->matrix[col][row] = CLOSED;
    in->matrix[row][col] = CLOSED;
    return (in->matrix);
}

t_room          *get_next_neighbor(t_in *in, t_room *node, t_room *neighbor)
{
    int     row;

    row = 0;
    while (row < in->room_count)
    {
        if (in->matrix[node->id][row] == 1)
        {
            neighbor = get_room(in->room, row);
            in->matrix = update_matrix(in, node->id, row);
            if (neighbor)
				return (neighbor);
		}
        row++;
    }
    return (NULL);
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
    node = node->next;
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
	}
    return (NULL);
}