/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/07 00:00:43 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            print_wave(t_in *in, t_room **paths, int *ant_list, int ant_id)
{
    t_room  *first;

    (void)in;
    first = paths[ant_list[ant_id]];
    while (paths[ant_list[ant_id]])
    {
		ft_printf("L%d-%d\n", ant_id, paths[ant_list[ant_id]]->id);
		paths[ant_list[ant_id]] = paths[ant_list[ant_id]]->trail;
	}
    paths[ant_list[ant_id]] = first;
}

void            print_ants(t_in *in, t_room **paths, int *ant_list)
{
	int   ant_id;

	ant_id = 0;
    while (ant_id < in->ant_size)
    {
        print_wave(in, paths, ant_list, ant_id);
        ant_id++;
    }
}

int             main(void)
{
    t_in        *in;
    t_room      **paths;
    int         *ant_list;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    ant_list = ant_calculus(in, paths);
    print_ants(in, paths, ant_list);
    free(ant_list);
    free(paths);
    free(in);
}