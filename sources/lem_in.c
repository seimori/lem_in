/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/06 05:40:57 by seimori          ###   ########.fr       */
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
    path->score = INF;
    path = path->trail;
    while (path != in->room)
    {
        in->room = remove_from_queue(in->room, path);
        path = path->trail;
    }
    return (in->room);
}

int             main(void)
{
    t_in        *in;
    t_room      **paths;
    int         max_paths;
    int         path_count;

    in = get_test_case();
    max_paths = get_max_paths(in);
    path_count = 0;
    paths = initialize_paths(in, max_paths);
    while (path_count < max_paths)
    {
        if (path_count > 0)
        {
            in->matrix = reset_visited(in);
			in->matrix = remove_path(in, paths[path_count - 1]);
            in->room = remove_path_from_queue(in, paths[path_count - 1]);
		}
		paths[path_count] = pathfinder(in);
		path_count++;
	}
    free(paths);
    free(in);
}