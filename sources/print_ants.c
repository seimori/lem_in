/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:32:14 by seimori           #+#    #+#             */
/*   Updated: 2020/03/27 05:50:40 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          **write_route(t_in *in, t_room **paths)
{
	int      path_id;

    
	path_id = 0;
    while (path_id < in->max_paths)
    {
        paths[path_id]->route = NULL;
        while (paths[path_id]->trail && paths[path_id]->trail->trail)
        {
            paths[path_id]->trail->route = paths[path_id];
            paths[path_id]->trail->ants = paths[path_id]->ants;
            paths[path_id] = paths[path_id]->trail;
        }
        path_id++;
    }
    return (paths);
}

void          create_ant_paths(t_in *in, t_room **paths, t_room **ant_paths)
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
		path_id = (path_id + 1) % in->max_paths;
		while (paths[path_id]->ants <= 0 && ant_id < in->ant_size)
            path_id = (path_id + 1) % in->max_paths;
    }
}

int				escape_end_room_check(t_in *in, t_room **ant_paths,
int ant_check)
{
	if (ant_paths[ant_check]->trail->id == in->end_room->id
	&& ant_paths[ant_check]->trail->trail != in->room)
		return (FALSE);
	else
		return (TRUE);
}

int             is_next_turn(t_in *in, t_room **ant_paths, int ant_id)
{
    int ant_check;

    ant_check = 0;
    if (ant_id >= in->ant_size)
        return (TRUE);
    while (ant_check < ant_id)
    {
		while (!ant_paths[ant_check])
            ant_check++;
		if (ant_check >= ant_id)
			return (FALSE);
		if (escape_end_room_check(in, ant_paths, ant_check)
		&& ant_paths[ant_check]->trail->id == ant_paths[ant_id]->id)
            return (TRUE);
        ant_check++;
    }
    return (FALSE);
}

int             get_lowest_ant_id(t_room **ant_paths)
{
    int ant_id;

    ant_id = 0;
    while (ant_paths[ant_id] == NULL)
        ant_id++;
    return (ant_id);
}

void            print_ants(t_in *in, t_room **paths)
{
	int     ant_id;
	t_room *ant_paths[in->ant_size];

	ant_id = 0;
    paths = write_route(in, paths);
    create_ant_paths(in, paths, ant_paths);
	if (ant_id < in->ant_size)
		ft_printf("\n");
    while (ant_id < in->ant_size)
    {
        ft_printf("L%d-%s ", ant_id + 1, ant_paths[ant_id]->name);
        ant_paths[ant_id] = ant_paths[ant_id]->route;
		ant_id++;
        if (is_next_turn(in, ant_paths, ant_id))
        {
            ant_id = get_lowest_ant_id(ant_paths);
			if (ant_id < in->ant_size)
				ft_printf("\n");
        }
    }
}