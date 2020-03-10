/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/10 03:02:02 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void          initialize_first(t_in *in, t_room **paths, t_room **first)
{
    int     path_id;

    path_id = 0;
    while (path_id < in->max_paths)
    {
        first[path_id] = paths[path_id];
        path_id++;
    }
}

t_room          **reset_paths_to_first(t_in *in, t_room **paths, t_room **first)
{
    int path_id;

    path_id = 0;
    while (path_id < in->max_paths)
    {
        paths[path_id] = first[path_id];
        path_id++;
    }
    return (paths);
}

int             get_path_id(t_in *in, int ant_id)
{
    long int     path_id;

    path_id = ant_id % in->max_paths;
    if (path_id < 0)
        path_id = -path_id;
    return ((int)path_id);
}

t_room          **write_route(t_in *in, t_room **paths)
{
	int      path_id;

    
	path_id = 0;
    while (path_id < in->max_paths)
    {
        paths[path_id]->route = in->end_room;
        while (paths[path_id]->trail->trail)
        {
            paths[path_id]->trail->route = paths[path_id];
            paths[path_id]->trail->ants = paths[path_id]->ants;
            paths[path_id] = paths[path_id]->trail;
        }
        path_id++;
    }
    return (paths);
}

void          initialize_ant_paths(t_in *in, t_room **paths, t_room **ant_paths)
{
	int     ant_id;
    int     path_id;

    ant_id = 0;
    path_id = 0;
    while (ant_id < in->ant_size)
    {
        ant_paths[ant_id] = paths[path_id];
        ant_id++;
        paths[path_id]->ants--;
		path_id = get_path_id(in, ant_id);
		while (paths[path_id]->ants <= 0 && ant_id < in->ant_size)
            path_id = (path_id + 1) % in->max_paths;
    }
}

void            print_ants(t_in *in, t_room **paths)
{
	int     ant_id;
	int     path_id;
	t_room *ant_paths[in->ant_size];

	ant_id = 0;
    path_id = 0;
    (void)path_id;
    paths = write_route(in, paths);
    initialize_ant_paths(in, paths, ant_paths);
    while (ant_id < in->ant_size)
    {
        ft_printf("L%d-%d ", ant_id + 1, ant_paths[ant_id]->id);
        ant_paths[ant_id] = ant_paths[ant_id]->route;
        ant_id++;
    }
}

int             main(void)
{
    t_in        *in;
    t_room      **paths;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    paths = ant_calculus(in, paths);
    print_ants(in, paths);
    free(paths);
    free(in);
}