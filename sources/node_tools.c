/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 05:06:30 by seimori           #+#    #+#             */
/*   Updated: 2020/07/03 05:07:06 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			copy_room_node(t_room *source, t_room copy)
{
	copy.id = source->id;
	copy.x = source->x;
	copy.y = source->y;
	copy.name = source->name;
	copy.score = source->score;
	copy.next = source->next;
	copy.previous = source->previous;
	copy.trail = source->trail;
	copy.route = source->route;
	copy.ants = source->ants;
	copy.duplicate = source->duplicate;
	return (copy);
}
