/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/08 15:57:28 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int            print_ant(t_room *first, t_room *path, int ant_num)
{
    if (!path->trail)
        return (0);
    print_ant(first, path->trail, ant_num);
    ft_printf("L%d-%d\n", ant_num, path->id);
    if (path == first)
		ft_printf("L%d-%d\n", ant_num, 0);
	return (1);
}

// void            print_ants(t_in *in, t_room **paths)
// {
//     int ant_num;
//     int path_id;

//     ant_num = 1;
//     while (ant_num <= in->ant_size)
//     {
//         path_id = 0;
//         while (path_id < in->max_paths)
//         {
// 			if (paths[path_id] && paths[path_id]->ants > 0)
// 			{
// 				print_ant(paths[path_id], paths[path_id], ant_num);
// 				paths[path_id]->ants--;
// 				ant_num++;
// 			}
//             path_id++;
// 		}
//     }
// }

int            print_ants(t_in *in, t_room *path, int ant_size)
{
    if (ant_size + path->score <= 0)
        return (0);
    print_ants(in, path, ant_size - 1);
    while (path && ant_size <= in->ant_size)
    {
        if (ant_size > 0)
			ft_printf("L%d-%d ", ant_size, path->id);
		ant_size++;
        path = path->trail;
    }
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
    print_ants(in, paths[0], in->ant_size);
    free(paths);
    free(in);
}