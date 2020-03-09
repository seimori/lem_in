/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/09 10:51:57 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// int            print_ants(t_in *in, t_room **paths, int ant_size)
// {
//     t_room  *temp;
//     int     path_id;

//     path_id = 0;
// 	if (ant_size + paths[path_id]->score <= 0)
//         return (0);
//     print_ants(in, paths, ant_size - 1);
//     temp = paths[path_id];
//     while (temp && ant_size <= in->ant_size)
//     {
// 		if (ant_size > 0)
// 			ft_printf("L%d-%d ", ant_size, temp->id);
// 		ant_size++;
// 		temp = temp->trail;
// 	}
//     ft_printf("\n");
//     return (1);
// }

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

void             print_ant(t_in *in, t_room **paths, int ant_size)
{
	int      path_id;
	t_room * first[in->max_paths];

	path_id = 0;
    initialize_first(in, paths, first);
    while (paths[path_id] && ant_size <= in->ant_size)
    {
        if (ant_size > 0)
			ft_printf("L%d-%d ", ant_size, paths[path_id]->id);
		ant_size++;
        paths[path_id] = paths[path_id]->trail;
        path_id = (path_id + 1) % in->max_paths;
	}
    paths = reset_paths_to_first(in, paths, first);
}

int            print_ants(t_in *in, t_room **paths, int ant_size)
{
    int     path_id;
    int     total_score;

    path_id = 0;
    total_score = 0;
    while (path_id < in->max_paths)
    {
        total_score += paths[path_id]->score;
        path_id++;
    }
	if (ant_size + total_score <= 0)
        return (0);
    print_ants(in, paths, ant_size - 1);
    print_ant(in, paths, ant_size);
    ft_printf("\n");
    return (1);
}

int             main(void)
{
    t_in        *in;
    t_room      **paths;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    paths = ant_calculus(in, paths);
    // print_ants(in, paths);
    print_ants(in, paths, in->ant_size);
    free(paths);
    free(in);
}