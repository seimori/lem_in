/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:52:01 by seimori           #+#    #+#             */
/*   Updated: 2020/06/30 17:41:10 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			*bellman_ford(t_in *in, t_room *path)
{
	t_room		*scan;
	size_t		room_count;

	scan = in->room;
	room_count = in->room_count;
	while (room_count > 0)
	{
		in = explore_node(in, scan);
		scan = scan->next;
		room_count--;
	}
	return (path);
}