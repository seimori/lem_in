/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:50:32 by seimori           #+#    #+#             */
/*   Updated: 2020/07/03 05:10:07 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				**make_node_directed(t_in *in, t_room *node)
{
	in->matrix[node->trail->id][node->id] = 0;
	in->matrix[node->id][node->trail->id] = -1;
	return (in->matrix);
}

t_in			*duplicate_node(t_in *in, t_room *node_in)
{
	t_room		node_out;

	node_out = copy_room_node(node_in, node_out);
	node_in->duplicate = DUPLICATE_IN;
	node_out.duplicate = DUPLICATE_OUT;
	node_out.previous = node_in;
	node_in->next = &node_out;
	in->matrix[node_out.id][node_in->id] = DUPLICATE;
	return (in);
}

t_in			*lock_path(t_in *in, t_room *node)
{
	while (node->trail != NULL)
	{
		in->matrix = make_node_directed(in, node);
		if (node != in->end_room)
			in = duplicate_node(in, node);
		node = node->trail;
	}
	return (in);
}

t_room			**suurballe(t_in *in, t_room **paths)
{
	int			path_id;

	path_id = 0;
	paths[0] = dijkstra(in, paths[0]);
	paths[1]->score = 2000;
	in = lock_path(in, paths[path_id]); //TODO Should I clear the scores of rooms to INF? Should there be an exception for path?
	paths[1] = bellman_ford(in);

	return (paths);
}