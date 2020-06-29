/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:50:32 by seimori           #+#    #+#             */
/*   Updated: 2020/06/29 03:26:23 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             **reset_visited(t_in *in)
{
    int col;
    int row;

    col = 0;
    while (col < in->room_count)
    {
        row = col + 1;
        while (row < in->room_count)
        {
            if (in->matrix[col][row] == VISITED)
            {
                in->matrix[col][row] = 1;
                in->matrix[row][col] = 1;
            }
            row++;
        }
        col++;
    }
    return (in->matrix);
}

int				**make_node_directed(t_in *in, t_room *node)
{
	in->matrix[node->trail->id][node->id] = 0;
	in->matrix[node->id][node->trail->id] = -1;
	return (in->matrix);
}

t_in			*duplicate_node(t_in *in, t_room *node_in)
{
	t_room		*node_out;

	node_out = copy_room_node(node_in);
	node_in->duplicate = DUPLICATE_IN;
	node_out->duplicate = DUPLICATE_OUT;
	node_out->previous = node_in;
	node_in->next = node_out;
	return (in);
}

t_in			*lock_path(t_in *in, t_room *path)
{
	while (path->trail != NULL)
	{
		in->matrix = make_node_directed(in, path);
		if (path != in->end_room)
			in = duplicate_node(in, path);
		path = path->trail;
	}
	return (in);
}

t_room			**suurballe(t_in *in, t_room **paths)
{
	int			path_id;

	path_id = 0;
	paths[0] = dijkstra(in); //TODO check why I get no path with 20.map
	in->matrix = reset_visited(in);
	in = lock_path(in, paths[path_id]);
	return (paths);
}