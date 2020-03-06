/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_neighbor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:05:44 by seimori           #+#    #+#             */
/*   Updated: 2020/03/06 04:07:34 by seimori          ###   ########.fr       */
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

int             **mark_visited(t_in *in, int col, int row)
{
    in->matrix[col][row] = VISITED;
    in->matrix[row][col] = VISITED;
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
            in->matrix = mark_visited(in, node->id, row);
            if (neighbor)
				return (neighbor);
		}
        row++;
    }
    return (NULL);
}