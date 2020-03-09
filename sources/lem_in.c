/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/09 02:54:04 by seimori          ###   ########.fr       */
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

void             print_ant(t_in *in, t_room **paths, int ant_size)
{
    t_room  *temp0;
    t_room  *temp1;

    temp0 = paths[0];
    temp1 = paths[1];
    while (temp0 && temp1 && ant_size <= in->ant_size)
    {
        if (ant_size > 0 && ant_size % in->max_paths)
        {
			ft_printf("L%d-%d ", ant_size, temp1->id);
            temp1 = temp1->trail;
        }
		else
        {
			ft_printf("L%d-%d ", ant_size, temp0->id);
            temp0 = temp0->trail;
        }
		ant_size++;
	}
}

int            print_ants(t_in *in, t_room **paths, int ant_size)
{
    int     path_id;

    path_id = 0;
	if (ant_size + paths[path_id]->score <= 0)
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