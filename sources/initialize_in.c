/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:45:31 by seimori           #+#    #+#             */
/*   Updated: 2020/03/16 00:39:14 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// t_room          *create_room_node(int id, int x, int y)
// {
//     t_room      *room;

//     room = (t_room*)ft_memalloc(sizeof(t_room));
//     room->id = id;
//     room->x = x;
//     room->y = y;
//     room->name = ft_itoa(id);
//     room->score = INF;
//     room->next = NULL;
//     room->trail = NULL;
//     room->route = NULL;
//     room->ants = 0;
//     return (room);
// }

t_room			*create_room_node(t_names *names)
{
	t_room		*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->id = names->id;
	room->x = names->x;
	room->y = names->y;
	room->name = names->name;
	if (names->startend == START)
		room->score = 0;
	else
		room->score = INF;
	room->next = NULL;
	room->trail = NULL;
	room->route = NULL;
	room->ants = 0;
	return (room);
}

t_tube          *create_tube_node(int in, int out)
{
    t_tube  *tube;

    tube = (t_tube*)ft_memalloc(sizeof(t_tube));
    tube->in = in;
    tube->out = out;
    tube->next = NULL;
    return (tube);
}

t_in            *initialize_in()
{
    t_in        *in;

    in = (t_in*)ft_memalloc(sizeof(t_in));
    in->ant_size = 0;
    in->room = NULL;
    in->tube = NULL;
    in->end_room = NULL;
    in->matrix = NULL;
    return (in);
}