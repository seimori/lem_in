/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_test_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:43:43 by seimori           #+#    #+#             */
/*   Updated: 2020/03/16 00:41:38 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room          *create_test_rooms(t_in *in)
{
	t_room *first_room;

	in->room = create_room_node(1, 23, 3);
	in->room_count++;
	first_room = in->room;
	first_room->score = 0;
	in->room->next = create_room_node(2, 16, 7);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(3, 16, 3);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(4, 16, 5);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(5, 9, 3);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(6, 1, 5);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(7, 4, 8);
	in->room = in->room->next;
	in->room_count++;
	in->room->next = create_room_node(0, 9, 5);
	in->end_room = in->room->next;
	in->room_count++;
	return (first_room);
}

t_tube          *create_test_tubes(t_in *in)
{
	t_tube *first_tube;

    in->tube = create_tube_node(0, 4);
    first_tube = in->tube;
    in->tube->next = create_tube_node(0, 6);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(1, 3);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(4, 3);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(5, 2);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(3, 5);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(4, 2);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(2, 1);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(7, 6);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(7, 2);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(7, 4);
    in->tube = in->tube->next;
    in->tube->next = create_tube_node(6, 5);
    return (first_tube);
}

t_in            *get_test_case()
{
	t_in   *in;

	in = initialize_in();
	// in->room = create_test_rooms(in);
	in->room = multi_path_rooms(in);
	// in->tube = create_test_tubes(in);
	in->tube = multi_path_test_tubes(in);
	in->matrix = generate_matrix(in);
	return (in);
}