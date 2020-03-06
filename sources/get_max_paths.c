/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:29:22 by seimori           #+#    #+#             */
/*   Updated: 2020/03/06 04:29:49 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             get_neighbors_count(t_in *in, t_room *room)
{
    int neighbors_count;
    int row;

    neighbors_count = 0;
    row = 0;
    while (row < in->room_count)
    {
        if (in->matrix[room->id][row] == 1)
            neighbors_count++;
        row++;
    }
    return (neighbors_count);
}

int             get_max_paths(t_in *in)
{
    int start_neighbors_count;
    int end_neighbors_count;

	start_neighbors_count = get_neighbors_count(in, in->room);
	end_neighbors_count = get_neighbors_count(in, in->end_room);
	if (start_neighbors_count <= end_neighbors_count)
		return (start_neighbors_count);
	else
        return (end_neighbors_count);
}