/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_neighbor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:05:44 by seimori           #+#    #+#             */
/*   Updated: 2020/07/01 16:27:09 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *get_room(t_room *node, int row_id)
{
    while (node)
    {
        if (node->id == row_id)
            return(node);
        node = node->next;
    }
    return (NULL);
}

int             **mark_visited(t_in *in, int col, int row)
{
    in->matrix[col][row] = VISITED;
    in->matrix[row][col] = VISITED;
    return (in->matrix);
}

t_room          *get_next_neighbor(t_in *in, t_room *node, t_room *neighbor)
{
    int     row;

	if (neighbor == node)
		row = 0;
	else
		row = neighbor->id + 1;
	while (row < in->room_count)
    {
        if (in->matrix[node->id][row] == 1)
        {
            neighbor = get_room(in->room, row);
            // in->matrix = mark_visited(in, node->id, row);
            if (neighbor)
				return (neighbor);
		}
        row++;
    }
    return (NULL);
}