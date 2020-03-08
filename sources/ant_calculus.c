/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_calculus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:14:00 by seimori           #+#    #+#             */
/*   Updated: 2020/03/08 01:51:14 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room             **ant_calculus(t_in *in, t_room **paths)
{
    int ant_count;
    int path_id;
    int ant_path;

    ant_count = 0;
    while (ant_count < in->ant_size)
    {
		path_id = 0;
		ant_path = 0;
        while (path_id < in->max_paths && paths[path_id])
        {
            if (paths[path_id]->score + paths[path_id]->ants 
            < paths[ant_path]->score + paths[ant_path]->ants)
                ant_path = path_id;
            path_id++;
        }
        paths[ant_path]->ants++;
        ant_count++;
    }
    return (paths);
}