/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:18:46 by seimori           #+#    #+#             */
/*   Updated: 2020/03/19 03:12:23 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             **remove_path(t_in *in, t_room *path)
{
    int row;

    path = path->trail;
    while (path != in->room)
	{
		row = 0;
		while (row < in->room_count)
		{
			if (in->matrix[path->id][row] == 1)
			{
				in->matrix[path->id][row] = LOCKED;
				in->matrix[row][path->id] = LOCKED;
			}
			row++;
		}
        path = path->trail;
	}
	return (in->matrix);
}

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

t_room          **initialize_paths(t_in *in, int max_paths)
{
    t_room      **paths;

    paths = (t_room**)ft_memalloc(sizeof(t_room*) * max_paths);
    paths[0] = in->room;
    return (paths);
}

t_room          *remove_path_from_queue(t_in *in, t_room *path)
{
    while (path != in->room)
    {
        in->room = remove_from_queue(in->room, path);
        path = path->trail;
    }
    return (in->room);
}

t_room      *reset_score(t_room *queue)
{
    t_room *first;

    first = queue;
    queue = queue->next;
    while (queue)
    {
        queue->score = INF;
        queue = queue->next;
    }
    return (first);
}

t_room **get_paths(t_in *in)
{
	int		path_count;
	t_room	**paths;

	path_count = 0;
	paths = initialize_paths(in, in->max_paths);
	while (path_count < in->max_paths)
	{
		if (path_count > 0)
		{
			in->matrix = reset_visited(in);
			in->matrix = remove_path(in, paths[path_count - 1]);
			in->room = remove_path_from_queue(in, paths[path_count - 1]->trail);
            in->room = reset_score(in->room);
		}
		paths[path_count] = pathfinder(in);
		if (paths[path_count] == NULL)
			return (paths);
		path_count++;
	}
	return (paths);
}