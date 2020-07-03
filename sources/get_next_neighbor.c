/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_neighbor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:05:44 by seimori           #+#    #+#             */
/*   Updated: 2020/07/03 04:52:30 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *get_room(t_room *node, int row_id)
{
    while (node)
    {
        if (node->id == row_id && node->duplicate != DUPLICATE_OUT)
            return(node);
        node = node->next;
    }
    return (NULL);
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
        if (in->matrix[node->id][row] != 0)
        {
            neighbor = get_room(in->room, row);
            if (neighbor)
				return (neighbor);
		}
        row++;
    }
    return (NULL);
}