/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_multi_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:42:31 by seimori           #+#    #+#             */
/*   Updated: 2020/03/12 19:07:13 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			*multi_path_rooms(t_in *in)
{
	t_room	*first_room;

	in->room = create_room_node(1, 0, 0);
	first_room = in->room;
	first_room->score = 0;
	in->room_count = 2;
	while (in->room_count < 12)
	{
		in->room->next = create_room_node(in->room_count, 0, 0);
		in->room = in->room->next;
		in->room_count++;
	}
	in->room->next = create_room_node(0, 0, 0);
	in->end_room = in->room->next;
	return (first_room);
}

t_tube			*multi_path_test_tubes(t_in *in)
{
	t_tube		*first_tube;

	in->tube = create_tube_node(1, 2);
	first_tube = in->tube;
	in->tube->next = create_tube_node(1, 6);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(2, 3);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(2, 7);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(3, 4);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(4, 5);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(5, 0);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(5, 10);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(5, 11);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(6, 8);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(7, 9);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(8, 10);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(9, 11);
	in->tube = in->tube->next;
	in->tube->next = create_tube_node(11, 0);
	in->tube = in->tube->next;
	return (first_tube);
}