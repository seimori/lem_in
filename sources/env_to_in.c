/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 17:10:45 by seimori           #+#    #+#             */
/*   Updated: 2020/03/16 01:29:40 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_in		*fill_rooms(t_env *e, t_in *in)
{
	t_room	*first;
	int		names_id;

	names_id = 1;
	in->room = create_room_node(e->names[0]);
	first = in->room;
	first->score = 0;
	while (names_id < in->room_count)
	{
		in->room->next = create_room_node(e->names[names_id]);
		if (e->names[names_id].startend == END)
			in->end_room = in->room->next;
		names_id++;
		in->room = in->room->next;
	}
	in->room = first;
	return (in);
}

t_in		*env_to_in(t_env *e)
{
	t_in	*in;

	in = initialize_in();
	in->ant_size = e->nb_ants;
	in->room_count = e->nb_room;
	in->matrix = e->links;
	in = fill_rooms(e, in);
	return (in);
}